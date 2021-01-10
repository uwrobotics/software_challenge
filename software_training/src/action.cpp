#include <ros/ros.h>
#include <actionlib/client/simple_action_client.h>
#include <actionlib>
#include <std_msgs/String.h>
#include <geometry_msgs/Twist.h>
#include <sstream>
#include <cmath>
#include "software_training/Distance.h"
#include <actionlib/server/simple_action_server.h>

int main (int argc, char **argv)
{
  ros::init(argc, argv, "action");
  
  ros::NodeHandle nh;
  ros::Publisher pub
       = nh.advertise<geometry_msgs::Twist>("/moving_turtle/cmd_vel", 1000);
  // create the action client
  // true causes the client to spin its own thread
  
  //actionlib::SimpleActionClient<goemetry_msgs::Twist>("action", true);
  actionlib::SimpleActionClient<software_training_assignment::Action> actionClient("action", true);

  Server server(n, "action", boost::bind(&execute, _1, &server), false);
  server.start();

  ROS_INFO("Waiting for action server to start.");
  // wait for the action server to start
  actionClient.waitForServer(); //will wait for infinite time

  ROS_INFO("Action server started, sending goal.");
  // send a goal to the action
  actionlib_tutorials::FibonacciGoal goal;
  goal.order = 20;
  ac.sendGoal(goal);

  //wait for the action to return
  bool finished_before_timeout = ac.waitForResult(ros::Duration(30.0));

  if (finished_before_timeout)
  {
    actionlib::SimpleClientGoalState state = ac.getState();
    ROS_INFO("Action finished: %s",state.toString().c_str());
  }
  else
    ROS_INFO("Action did not finish before the time out.");

  //exit
  return 0;
}
