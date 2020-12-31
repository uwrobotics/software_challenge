#include "ros/ros.h"
#include "actionlib/server/simple_action_server.h"
#include "software_training/software_training_actionAction.h"
#include "geometry_msgs/Twist.h"
#include <string>

class moving_turtle_action_server{

    protected:
        //create node handle
        ros::NodeHandle nh;
        //create action server
        actionlib::SimpleActionServer
            <software_training::software_training_actionAction> action_server;
        //action server name
        std::string name;
        //create feedback for action server
        software_training::software_training_actionFeedback feedback;
        //create result for action server 
        software_training::software_training_actionResult result; 
        //create publisher to cmd_vel topic for moving turtle
        ros::Publisher pub_moving_turtle;
    public:
        //constructor
        moving_turtle_action_server(std::string _name_of_server);
        //callback function
        void executeCB(const software_training::software_training_actionGoalConstPtr& goal);
        
};

moving_turtle_action_server::moving_turtle_action_server(std::string _name_of_server):
    action_server(nh,_name_of_server, boost::bind(&moving_turtle_action_server::executeCB, this, _1), false),
    name(_name_of_server)
{
    //start action server
    action_server.start();
    // instantiate publisher
    pub_moving_turtle = nh.advertise<geometry_msgs::Twist>("/moving_turtle/cmd_vel",1000);
}

void moving_turtle_action_server::executeCB(
    const software_training::software_training_actionGoalConstPtr& goal)
{
    //set a variable to check if finished 
    //set ros rate
    ros::Rate loop_rate{1};
    //get components of the goal
    double x_goal = goal->x_position_to_waypoint;
    double y_goal = goal->y_position_to_waypoint;
    //create a message to publish
    geometry_msgs::Twist msg;
    //initialize message to be published
    msg.linear.x = 0.0;
    msg.linear.y = 0.0;
    msg.linear.z = 0.0;
    msg.angular.x = 0.0;
    msg.angular.y = 0.0;
    msg.angular.z = 0.0;

    //start of timer
    ros::Time start = ros::Time::now();

    while(ros::ok() && action_server.isActive() && !action_server.isNewGoalAvailable()){
        //publish to cmd_vel topic one interval at a time  
        if(msg.linear.x < x_goal || msg.linear.y < y_goal){
            if(msg.linear.x < x_goal){
                msg.linear.x++;
                feedback.x_distance_to_goal = x_goal - msg.linear.x; 
            }
            if(msg.linear.y < y_goal){
                msg.linear.y++;
                feedback.y_distance_to_goal = y_goal - msg.linear.y;
            }
            //publish message
            pub_moving_turtle.publish(msg);
            //publish feedback
            action_server.publishFeedback(feedback);
        }
        else if(msg.linear.x >= x_goal && msg.linear.y >= y_goal) break;
        loop_rate.sleep();
    }
    //check to see if action is still up and running since we broke the loop
    if(!ros::ok() || action_server.isPreemptRequested() || !action_server.isActive()){
        ROS_ERROR_STREAM("moving_turtle_action_server NOT AVAILABLE/SHUTDOWN/NEW GOAL");
    }
    else{
        //end of timer 
        ros::Time end = ros::Time::now();
        //get total time 
        ros::Duration res_time = end - start; 
        result.total_time = res_time; 
        //set result
        action_server.setSucceeded(result);
    }

}

int main(int argc, char **argv){
    ros::init(argc, argv, "moving_turtle_action_node");    
    moving_turtle_action_server as("mover");
    ros::spin();
    return 0;
}