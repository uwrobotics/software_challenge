#include "software_training/turtle_distance_publisher.hpp"

namespace software_training {

turtle_distance_publisher::turtle_distance_publisher(const rclcpp::NodeOptions& options) : rclcpp::Node("turtle_distance_publisher", options) {
    publisher = this->create_publisher<software_training::msg::Distance>("/turtle_distance", 10);
    timer = this->create_wall_timer(1000ms, std::bind(&turtle_distance_publisher::publish, this));
    
    stationary_turtle_subscription = this->create_subscription<turtlesim::msg::Pose>(
        "/stationary_turtle/pose", 
        10, 
        std::bind(&turtle_distance_publisher::stationary_turtle_callback, this, std::placeholders::_1)
    );

    moving_turtle_subscription = this->create_subscription<turtlesim::msg::Pose>(
        "/moving_turtle/pose", 
        10, 
        std::bind(&turtle_distance_publisher::moving_turtle_callback, this, std::placeholders::_1)
    );
}

void turtle_distance_publisher::publish(void) {
    auto msg = software_training::msg::Distance();
    msg.delta_x = std::fabs(stationary_turtle_position.x - moving_turtle_position.x);
    msg.delta_y = std::fabs(stationary_turtle_position.y - moving_turtle_position.y);
    msg.distance = std::sqrt(std::pow(msg.delta_x, 2) + std::pow(msg.delta_y, 2));
    publisher->publish(msg);
}

void turtle_distance_publisher::stationary_turtle_callback(const turtlesim::msg::Pose::SharedPtr msg) {
    stationary_turtle_position.x = msg->x;
    stationary_turtle_position.y = msg->y;
}

void turtle_distance_publisher::moving_turtle_callback(const turtlesim::msg::Pose::SharedPtr msg) {
    moving_turtle_position.x = msg->x;
    moving_turtle_position.y = msg->y;
}

}

#include "rclcpp_components/register_node_macro.hpp"

RCLCPP_COMPONENTS_REGISTER_NODE(software_training::turtle_distance_publisher)
