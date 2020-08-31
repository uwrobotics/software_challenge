#include "ros/ros.h"

#include "Turtle.h"
#include "StationaryTurtle.h"
#include "MovingTurtle.h"

#include "DistancePublisher.h"

int main(int argc, char **argv) {

    ros::init(argc, argv, "main");

    ros::NodeHandle n;
    ros::Rate loop_rate(1);
    
    // kill current turtle loop
    while (!Turtle::kill(n, "turtle1")) {
        loop_rate.sleep();
        ROS_ERROR("Failed to clear all turtles");
    }
    ROS_INFO("Cleared all turtles");

    // spawn new turtles
    StationaryTurtle* stationaryTurtle = StationaryTurtle::getInstance(n);
    MovingTurtle* movingTurtle = MovingTurtle::getInstance(n);

    // distance publisher
    DistancePublisher dist_pub(n, stationaryTurtle, movingTurtle);
    while(ros::ok()) {
        dist_pub.publish();
        loop_rate.sleep();
    }

    return 0;
}
