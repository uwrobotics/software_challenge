/*
Action server for moving the turtle 
*/

#include <ros/ros.h> 
#include <actionlib/server/simple_action_server.h>
#include <software_training_assignment/moveTurtle.h>
//Subscribe to the geometry_msgs/Twist topic 
#include <geometry_msgs/Twist.h>
#include <math.h>

//Class to define the action server
class MoveTurtleAction {
    protected: 
        ros::NodeHandle nh; 
        actionlib::SimpleActionServer<software_training_assignment::moveTurtle> as;
        std::string action_name; 
        software_training_assignment::moveTurtleFeedback feedback; 
        software_training_assignment::moveTurtleResult result; 

    public: 

        MoveTurtleAction(std::string name) : 
            as(nh, name, boost::bind(&MoveTurtleAction::executeCB, this, _1), false, action_name(name)) {
                as.start();
            }

        ~MoveTurtleAction(void){}

        void executeCB(const software_training_assignment::moveTurtleGoalConstPtr &goal){

            bool success = false; 
            geometry_msgs::Twist vel_msg;
            ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 10);
            int end_pos_x = goal->abs_x;
            int end_pos_y = goal->abs_y; 
            double distance = sqrt(end_pos_x*end_pos_x + end_pos_y*end_pos_y);
            double elapsed_dist = 0;

            //start time
            double t0 = ros::Time::now().toSec();
            //move turtle to the end position using the unit vector for the velocity
            vel_msg.linear.x = (end_pos_x/distance);
            vel_msg.linear.y = (end_pos_y/distance);
            vel_msg.linear.z = 0;
            vel_msg.angular.x = 0; 
            vel_msg.angular.y = 0;
            vel_msg.angular.z = 0;

            //publisher message
            pub.publish(vel_msg);
            
            while(elapsed_dist < distance){
                double t1 = ros::Time::now().toSec();
                double t_diff = t1 - t0; 

                elapsed_dist = sqrt(vel_msg.linear.x*vel_msg.linear.x + vel_msg.linear.y*vel_msg.linear.y)*t_diff;
                feedback.abs_distance = elapsed_dist; 
            }

            //stop the turtle from moving
            vel_msg.linear.x = 0;
            vel_msg.linear.y = 0;
            pub.publish(vel_msg);

            //Get the stop time
            double t_end = ros::Time::now().toSec();

            //set the result
            result.time = (int) (t_end - t0); 

        }
};

int main(int argc, char **argv) {

    ros::init(argc, argv, "moveTurtle");
    MoveTurtleAction moveTurtle("moveTurtle");
    ros::spin();

    return 0; 

}