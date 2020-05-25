#include "turtle/turtle.h"

void turtle::callback(const turtlesim::Pose::ConstPtr& msg){
  this->x = msg->x;
  this->y = msg->y;
  this->theta = msg->theta;
}