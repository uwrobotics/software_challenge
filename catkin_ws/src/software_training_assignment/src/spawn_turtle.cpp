#include "spawn_turtle.h"

void spawn_turtle(ros::NodeHandle& n, std::string name, int x, int y) {
    ros::ServiceClient client = n.serviceClient<turtlesim::Spawn>("spawn");

    ros::service::waitForService("spawn");

    turtlesim::Spawn spawn;
    spawn.request.x = x;
    spawn.request.y = y;
    spawn.request.theta = 0;
    spawn.request.name = name;

    if (client.call(spawn)){
        ROS_INFO("%s is spawned", name.c_str());
    }else{
        ROS_ERROR("Failed to spawn %s boi", name.c_str());
    }
}