#include "software_training/move_turtle1_in_circle_publisher.hpp"

namespace software_training {

move_turtle1_in_circle_publisher::move_turtle1_in_circle_publisher(const rclcpp::NodeOptions& options) : rclcpp::Node("move_turtle1_in_circle_publisher", options) {
    publisher = this->create_publisher<geometry_msgs::msg::Twist>("/turtle1/cmd_vel", 10);
    timer = this->create_wall_timer(10ms, std::bind(&move_turtle1_in_circle_publisher::publish, this));
}

void move_turtle1_in_circle_publisher::publish(void) {
    auto msg = geometry_msgs::msg::Twist();
    msg.linear.x = 1;
    msg.angular.z = 1;
    publisher->publish(msg);
}

}

#include "rclcpp_components/register_node_macro.hpp"

RCLCPP_COMPONENTS_REGISTER_NODE(software_training::move_turtle1_in_circle_publisher)
