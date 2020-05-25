#include "ros/ros.h"
#include <string>
#include "turtlesim/Kill.h"
#include "std_srvs/Empty.h"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "turtlesim_clear_node");
  ros::NodeHandle n;
  ros::ServiceClient clearClient = n.serviceClient<std_srvs::Empty>("reset");
  std_srvs::Empty clearRequest;
  clearClient.call(clearRequest);
  ros::ServiceClient killClient = n.serviceClient<turtlesim::Kill>("kill");
  turtlesim::Kill killRequest;
  killRequest.request.name = "turtle1";
  killClient.call(killRequest);
}
