#ifndef CLEAR_H
#define CLEAR_H

#include "rclcpp/rclcpp.hpp"
#include "rclcpp_components/register_node_macro.hpp"

#include <turtlesim/srv/kill.hpp>
#include <visibility.h>

namespace composition
{
class ClearTurtle : public rclcpp::Node
{
    public:
        SOFTWARE_TRAINING_PUBLIC
        explicit ClearTurtle(const rclcpp::NodeOptions & options);

    private:
        SOFTWARE_TRAINING_LOCAL
        rclcpp::Client<turtlesim::srv::Kill>::SharedPtr client;
        rclcpp::TimerBase::SharedPtr timer;

        void kill_turtles();

};
}

#endif