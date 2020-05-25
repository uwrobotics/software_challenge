#include <ros/ros.h>
#include <actionlib/server/simple_action_server.h>
#include <turtlesim_editor/turtlesimAction.h>
#include <turtlesim/Pose.h>
#include <geometry_msgs/Twist.h>
#include <cmath>
#include "turtle/turtle.h"

class turtlesimAction
{
protected:
  ros::NodeHandle nh_;
  actionlib::SimpleActionServer<turtlesim_editor::turtlesimAction> as_;
  ros::Time starttime = ros::Time::now();
  turtlesim_editor::turtlesimFeedback feedback_;
  turtlesim_editor::turtlesimResult result_;

public:
  turtlesimAction(std::string name) :
    as_(nh_, name, boost::bind(&turtlesimAction::turtlesimGoalConstPtr, this, _1), false) 
  {
    as_.start();
  }

  ~turtlesimAction(void)
  {
  }

  void turtlesimGoalConstPtr(const turtlesim_editor::turtlesimGoalConstPtr &goal)
  {
    ros::Rate r(1);
    bool success = true;
    turtle moving;
    ros::Subscriber moving_turtle = this->nh_.subscribe("moving_turtle/pose", 1000, &turtle::callback, &moving);
    float diffX = abs(moving.x - goal->x);
    float diffY = abs(moving.y - goal->y);
    feedback_.distance = sqrt(pow(diffX, 2) + pow(diffY, 2));
    geometry_msgs::Twist moveDistance;
    while(feedback_.distance > 0.05)
    {
        diffY = abs(moving.y - goal->y);
        diffX = abs(moving.x - goal->x);
        moveDistance.linear.x = diffX;
        moveDistance.linear.y = diffY;
        ros::Publisher moveTurtle =  this->nh_.advertise<geometry_msgs::Twist>("moving_turtle/cmd_vel", 1000);
        moveTurtle.publish(moveDistance);
        this->as_.publishFeedback(feedback_);
    }

    if(success)
    {
      result_.timeTaken = ros::Time::now() - this->starttime;
      as_.setSucceeded(result_);
    }
  }


};


int main(int argc, char** argv)
{
  ros::init(argc, argv, "turtlesim_move");
  turtlesimAction turtlesimAction("moving_turtle");
  ros::spin();
  return 0;
}