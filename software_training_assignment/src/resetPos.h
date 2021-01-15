#ifndef RESETPOS_H
#define RESETPOS_H

#include <ros/ros.h>

bool resetPos(std_srvs::Empty::Request &req,
	      std_srvs::Empty::Response &res);

#endif