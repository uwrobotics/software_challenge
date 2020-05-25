#include "ros/ros.h"
#include "turtlesim_editor/distance.h"
#include "turtlesim/Pose.h"
#include <string>
#include <cmath>
#include "turtle/turtle.h"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "distance_publisher");
  ros::NodeHandle n;
  ros::Publisher distance_pub = n.advertise<turtlesim_editor::distance>("distance", 1000);
  turtle stationary;
  turtle moving;
  ros::Subscriber stationary_turtle_location = n.subscribe("stationary_turtle/pose", 1000, &turtle::callback, &stationary);
  ros::Subscriber moving_turtle_location = n.subscribe("moving_turtle/pose", 1000, &turtle::callback, &moving);
  ros::Rate loop_rate(10);
  while (ros::ok())
  {
    turtlesim_editor::distance msg;
    msg.x = abs(stationary.x - moving.x);
    msg.y = abs(stationary.y - moving.y);
    msg.total = sqrt(pow(msg.x, 2) + pow(msg.y, 2));
    distance_pub.publish(msg);
    ros::spinOnce();
    loop_rate.sleep();
  }


  return 0;
}