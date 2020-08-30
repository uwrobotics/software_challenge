#include "DistancePublisher.h"

#include "software_training_assignment/Distance.h"

#include <cmath>

// ctor
DistancePublisher::DistancePublisher(ros::NodeHandle &n, Turtle* t1, Turtle* t2) : n_{n}, t1_{t1}, t2_{t2} {
    // init ros distance publisher
    dist_pub_ = n_.advertise<software_training_assignment::Distance>("distance_publisher", 1000);
}

void DistancePublisher::publish() {
    turtlesim::Pose t1_Position = t1_->getPosition();
    turtlesim::Pose t2_Position = t2_->getPosition();

    // set message
    software_training_assignment::Distance msg;
    msg.x = t1_Position.x - t2_Position.x;
    msg.y = t1_Position.y - t2_Position.y;
    msg.distance = sqrt(pow(msg.x, 2) + pow(msg.y, 2));

    ROS_INFO_STREAM(std::setprecision(2) << std::fixed << " distance: " << msg.x << " " << msg.y << " " << msg.distance);
    
    // publish
    dist_pub_.publish(msg);
    ros::spinOnce();
}
