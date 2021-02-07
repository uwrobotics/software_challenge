#ifndef SPAWN_TURTLE_H
#define SPAWN_TURTLE_H

#include <ros/ros.h>
#include "turtlesim/Spawn.h"
void spawn_turtle (ros::NodeHandle& n, std::string name, int x, int y);

#endif
