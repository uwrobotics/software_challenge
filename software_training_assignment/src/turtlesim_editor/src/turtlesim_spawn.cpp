#include "ros/ros.h"
#include <string>
#include "turtlesim/Spawn.h"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "turtlesim_clear_node");
  ros::NodeHandle n;
  ros::ServiceClient client = n.serviceClient<turtlesim::Spawn>("spawn");
  turtlesim::Spawn stationary_turtle;
  stationary_turtle.request.x = 5;
  stationary_turtle.request.y = 5;
  stationary_turtle.request.theta = 0;
  stationary_turtle.request.name = "stationary_turtle";
  client.call(stationary_turtle);
  turtlesim::Spawn moving_turtle;
  moving_turtle.request.x = 25;
  moving_turtle.request.y = 10;
  moving_turtle.request.theta = 0;
  moving_turtle.request.name = "moving_turtle";
  client.call(moving_turtle);
}
