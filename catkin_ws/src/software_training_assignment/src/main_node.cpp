#include "ros/ros.h"
#include "turtlesim/Spawn.h"
#include "std_srvs/Empty.h"
#include "turtlesim/Pose.h"
#include "spawn_turtle.h"
#include "software_training_assignment/distance.h"
#include <cmath>

class Turtles{
private:
    ros::NodeHandle n;

public:
    Turtles();
    int turtle_dist_x;
    int turtle_dist_y;
    int turtle_dist_abs;
    void received_moving_pose(const turtlesim::Pose& msg);
    void clear_turtles();
    void spawn_two_turtles();
};

Turtles::Turtles() {
    clear_turtles();
    spawn_two_turtles();

    ros::Subscriber sub = n.subscribe("/moving/pose", 100, &Turtles::received_moving_pose, this);
}

void Turtles::clear_turtles() {
    ros::ServiceClient client = n.serviceClient<std_srvs::Empty>("clear");

    ros::service::waitForService("clear");

    std_srvs::Empty clear;

    if (client.call(clear)){
        ROS_INFO("Cleared playground");
    }else{
        ROS_ERROR("Failed to clear playground");
    }
}

void Turtles::spawn_two_turtles() {
    spawn_turtle(n, "stationary", 5, 5);
    spawn_turtle(n, "moving", 25, 10);
}

void Turtles::received_moving_pose(const turtlesim::Pose& msg){
    turtle_dist_x = abs(msg.x - 5);
    turtle_dist_y = abs(msg.y - 5);
    turtle_dist_abs = floor(pow(pow(turtle_dist_x, 2) + pow(turtle_dist_y, 2), 0.5));
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "turtles");
    ros::NodeHandle n;
    Turtles node;
    ros::Publisher dist_pub = n.advertise<software_training_assignment::distance>("distance", 1000);
    ros::Rate loop_rate(10);

    while (ros::ok()) {
        software_training_assignment::distance msg;
        msg.dist_x = node.turtle_dist_x;
        msg.dist_y = node.turtle_dist_y;
        msg.dist_abs = node.turtle_dist_abs;
        dist_pub.publish(msg);
    }

    return 0;
}