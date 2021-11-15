#include "rotate_turtle1.hpp"

namespace composition
{

RotateTurtle::RotateTurtle(const rclcpp::NodeOptions & options)
    : Node("rotate_turtle")
{
    this->publisher = this->create_publisher<geometry_msgs::msg::Twist>("turtle1/cmd_vel", 10);
    callback();
}

void RotateTurtle::callback()
{
    RCLCPP_INFO(this->get_logger(), "Here");

    auto msg = geometry_msgs::msg::Twist();

    auto ang = geometry_msgs::msg::Vector3();
    ang.z = 5;

    msg.angular = ang;

    publisher->publish(msg);
}

}

RCLCPP_COMPONENTS_REGISTER_NODE(composition::RotateTurtle)