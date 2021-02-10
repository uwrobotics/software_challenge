#include <ros/ros.h>
#include <actionlib/server/simple_action_server.h>
#include <software_training_assignment/move_moving_turtleAction.h>
#include <cmath>
#include "turtlesim/Pose.h"
#include "geometry_msgs/Twist.h"

class MoveMovingTurtle
{
protected:

  ros::NodeHandle nh_;
  actionlib::SimpleActionServer<software_training_assignment::move_moving_turtleAction> as_;
  std::string action_name_;
  // create messages that are used to published feedback/result
  software_training_assignment::move_moving_turtleFeedback feedback_;
  software_training_assignment::move_moving_turtleResult result_;
  ros::Publisher move_moving_turtlePub;
public:
    int x;
    int y;
    MoveMovingTurtle(std::string name) :
    as_(nh_, name, boost::bind(&MoveMovingTurtle::executeCB, this, _1), false),
    action_name_(name)
    {
        as_.start();
        ROS_INFO("Server started");
        ros::Subscriber sub = nh_.subscribe("/moving/pose", 100, &MoveMovingTurtle::received_moving_pose, this);
        move_moving_turtlePub = nh_.advertise<geometry_msgs::Twist>("moving/cmd_vel", 1000);
    }

    ~MoveMovingTurtle(void)
    {
    }

    void received_moving_pose(const turtlesim::Pose& msg){
        x = msg.x;
        y = msg.y;
    }

    void executeCB(const software_training_assignment::move_moving_turtleGoalConstPtr &goal)
    {
        // helper variables
        ros::Rate r(1);
        bool success = false;
        int xgoal = goal->waypoint_x;
        int ygoal = goal->waypoint_y;

        geometry_msgs::Twist msg;
        msg.linear.x = 0;
        msg.linear.y = 0;
        msg.linear.z = 0;
        msg.angular.x = 0;
        msg.angular.y = 0;
        msg.angular.z = 0;

        ros::Time start = ros::Time::now();

        while(ros::ok() && as_.isActive())
        {
            if (abs(xgoal-x) <= 1 && abs(ygoal-y) <= 1){
                success = true;
                break;
            }
            else{
                if (abs(xgoal-x) > 1) msg.linear.x ++;
                if (abs(ygoal-y) > 1) msg.linear.y ++;
                feedback_.distance_to_goal = floor(pow(pow(xgoal-x,2)+pow(ygoal-y,2),0.5));
                move_moving_turtlePub.publish(msg);
                as_.publishFeedback(feedback_);
            }
        }

        if (success){
            ros::Time currTime = ros::Time::now();
            ros::Duration timeTaken = currTime - start;
            result_.time_taken = timeTaken;
            as_.setSucceeded(result_);
        }

    }
};


int main(int argc, char** argv)
{
  ros::init(argc, argv, "move_moving_turtle");

  MoveMovingTurtle move_turtle();
  ros::spin();
  return 0;
}