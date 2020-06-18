#include <ros/ros.h>
#include <actionlib/client/simple_action_client.h>
#include <actionlib/client/terminal_state.h>
#include <software_training_assignment/TurtleSeekerAction.h>

/**
* ActionClient node to test the ActionServer in custom turtle
* USAGE: Pass in paramters _x, _y as coordinates of destination
*/


int main (int argc, char **argv)
{
  ros::init(argc, argv, "test_tseeker");
  ros::NodeHandle n;
  int xval,yval;
  n.getParam("/test_tseeker/x", xval);
  n.getParam("test_tseeker/y", yval);
  ROS_INFO("Xval %d", xval);
  ROS_INFO("yval %d", yval);
  // create the action client
  // true causes the client to spin its own thread
  actionlib::SimpleActionClient<software_training_assignment::TurtleSeekerAction> ac("turtle_seek", true);
  ROS_INFO("Waiting for action server to start.");
  // wait for the action server to start
  ac.waitForServer(); //will wait for infinite time

  ROS_INFO("Action server started, sending goal.");
  // send a goal to the action
  software_training_assignment::TurtleSeekerGoal goal;
  goal.x = xval;
  goal.y = yval;
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
