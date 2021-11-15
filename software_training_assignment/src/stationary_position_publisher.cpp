#include "stationary_position_publisher.hpp"

using namespace std::placeholders;

namespace composition
{

StationaryPosPublisher::StationaryPosPublisher(const rclcpp::NodeOptions &options)
    : Node("stationary_position_publisher", options)
{
    RCLCPP_INFO(this->get_logger(), "HERE");
    publisher = this->create_publisher<software_training_assignment::msg::Position>("pos_dis", 10);

    pose_sub = this->create_subscription<turtlesim::msg::Pose>("moving_turtle/pose",0, 
        std::bind(&StationaryPosPublisher::get_pose, this, _1));

}

void StationaryPosPublisher::get_pose(const turtlesim::msg::Pose::SharedPtr currentPose) {
    
    float mov_x = currentPose->x;
    float mov_y = currentPose->y;
    
    float stat_x = turtles.find("stationary_turtle")->second[0];
    float stat_y = turtles.find("stationary_turtle")->second[1];

    float distance = pow(pow(mov_x - stat_x, 2) + pow(mov_y - stat_y, 2), 0.5);

    auto message = software_training_assignment::msg::Position();
    message.x = stat_x;
    message.y = stat_y;
    message.distance = distance;

    publisher->publish(message);

    RCLCPP_INFO(this->get_logger(), std::to_string(distance));

    rclcpp::shutdown();
}

}

RCLCPP_COMPONENTS_REGISTER_NODE(composition::StationaryPosPublisher)