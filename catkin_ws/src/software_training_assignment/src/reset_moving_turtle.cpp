#include "ros/ros.h"
#include "turtlesim/Spawn.h"
#include "turtlesim/Kill.h"
#include "spawn_turtle.h"
#include "software_training_assignment/reset_moving_turtle.h"

bool reset_moving_turtle(software_training_assignment::reset_moving_turtle::Request &req,
                         software_training_assignment::reset_moving_turtle::Response &res) {
    ros::NodeHandle n;

    ros::ServiceClient killClient = n.serviceClient<turtlesim::Kill>("kill");

    ros::service::waitForService("kill");

    turtlesim::Kill kill;
    kill.request.x = x;
    kill.request.y = y;
    kill.request.theta = 0;
    kill.request.name = name;

    if (killClient.call(kill)){
        ROS_INFO("%s is spawned", spawn.response.name);
    }else{
        ROS_ERROR("Failed to spawn %s boi", name);
    }

    spawn_turtle(n, "moving", 25, 10);
}


int main(int argc, char **argv) {
    ros::init(argc, argv, "resetMoving");
    ros::NodeHandle n;

    ros::ServiceServer service = n.advertiseService("resetMoving", reset_moving_turtle);
    ROS_INFO("Ready to reset moving turtle");
    ros::spin();
    return 0;
}