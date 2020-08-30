#include "Turtle.h"

// ctor
Turtle::Turtle(ros::NodeHandle &n, float x, float y, std::string name) : n_{n}, startX_{x}, startY_{y}, name_{name} {
    // spawn the turtle
    if (_spawn()) {
        ROS_INFO("Spawned new %s", name.c_str());
    } else {
        ROS_ERROR("Failed to spawn new %s", name.c_str());
    }

    // init position subscriber
    poseSubscriber_ = n_.subscribe(name_ + "/pose", 1000, &Turtle::_positionCallback, this);
}

bool Turtle::kill(ros::NodeHandle &n, std::string name) {
    // init kill service client
    ros::ServiceClient killClient = n.serviceClient<turtlesim::Kill>("kill");
    turtlesim::Kill killSrv;
    
    killSrv.request.name = name;

    // attempt to kill turtle
    return killClient.call(killSrv);
}

// Update and return current position
turtlesim::Pose Turtle::getPosition() const {
    ros::spinOnce();
    return currentPosition_;
}

void Turtle::_positionCallback(const turtlesim::Pose &msgIn) {
    ROS_INFO_STREAM(std::setprecision(2) << std::fixed << name_ << " position: " << msgIn.x << ", " << msgIn.y);
    currentPosition_ = msgIn;
}

bool Turtle::_spawn() {
    // init spawning service client
    ros::ServiceClient spawnClient = n_.serviceClient<turtlesim::Spawn>("spawn");
    turtlesim::Spawn spawnSrv;

    // set request
    spawnSrv.request.x = startX_;
    spawnSrv.request.y = startY_;
    spawnSrv.request.theta = 0;
    spawnSrv.request.name = name_;

    // attempt to spawn turtle
    return spawnClient.call(spawnSrv);
}
