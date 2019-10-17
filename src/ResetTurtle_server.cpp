#include "ros/ros.h"
#include "software_training_assignment/ResetTurtle.h"
#include "turtlesim/TeleportAbsolute.h"

ros::ServiceClient client;

//service to reset pose
bool reset(software_training_assignment::ResetTurtle::Request &req,
         software_training_assignment::ResetTurtle::Response &res)
{

  //input to reset turtle service class
  turtlesim::TeleportAbsolute srv;
  srv.request.x = req.x;
  srv.request.y = req.y;
  srv.request.theta = req.theta;
  res.call = true; 

if (client.call(srv))
  {
    ROS_INFO("Successful");
  }
  
  else
  {
    res.call = false;
  }

  //sending back pose
  ROS_INFO("Request: moving_turtle");
  ROS_INFO("sending back response: Successful");
  return true;
}

int main(int argc, char **argv)
{
  //init
  ros::init(argc, argv, "ResetTurtle_server");
  ros::NodeHandle n;

  client = n.serviceClient<turtlesim::TeleportAbsolute>("moving_turtle/teleport_absolute");
  ros::ServiceServer service = n.advertiseService("ResetTurtle", reset);

  ROS_INFO("Ready to Reset Turtle.");
  ros::spin();

  return 0;
}
