#include "StationaryTurtle.h"

StationaryTurtle* StationaryTurtle::getInstance(ros::NodeHandle &n) {
    // lazy instantiation
    static StationaryTurtle instance_(n);
    return &instance_;
}

// ctor
StationaryTurtle::StationaryTurtle(ros::NodeHandle &n) : Turtle(n, 5, 5, "stationary_turtle") {}
