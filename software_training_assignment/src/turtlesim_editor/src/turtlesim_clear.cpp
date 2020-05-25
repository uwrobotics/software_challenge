#include "ros/ros.h"
#include <string>
#include "turtlesim/Kill.h"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "turtlesim_clear_node");
  ros::NodeHandle n;
  ros::ServiceClient client = n.serviceClient<turtlesim::Kill>("kill");
  turtlesim::Kill srv;
  srv.request.name = "turtle1";
  client.call(srv);
}
