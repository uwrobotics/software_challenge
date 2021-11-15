#ifndef ROTATE_H
#define ROTATE_H

#include "rclcpp/rclcpp.hpp"
#include "rclcpp_components/register_node_macro.hpp"

#include <geometry_msgs/msg/twist.hpp>

namespace composition
{
class RotateTurtle : public rclcpp::Node
{
    public:
        explicit RotateTurtle(const rclcpp::NodeOptions & options);

    private:
        rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher;
        void callback();    
};
}

#endif