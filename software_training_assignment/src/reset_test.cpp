#include "ros/ros.h"
#include "software_training_assignment/Reset.h"
#include <cstdlib>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "reset_test");
  ros::NodeHandle n;
  ros::ServiceClient client = n.serviceClient<software_training_assignment::Reset>("reset_moving_turtle");
  software_training_assignment::Reset srv;

  if (client.call(srv))
  {
    ROS_INFO("reset_moving_turtle service called. Result: %d", srv.response.success);
  }
  else
  {
    ROS_ERROR("Failed to call service reset_moving_turtle");
    return 1;
  }

  return 0;
}
