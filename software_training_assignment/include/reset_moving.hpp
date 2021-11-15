#ifndef RESET_H
#define RESET_H

#include "rclcpp/rclcpp.hpp"
#include "rclcpp_components/register_node_macro.hpp"

#include <visibility.h>
#include <software_training_assignment/srv/example_service.hpp>
#include <turtlesim/srv/teleport_absolute.hpp>

#include <turtle_info.hpp>
#include <string>

namespace composition
{
class ResetMoving : public rclcpp::Node
{
    public:
        explicit ResetMoving(const rclcpp::NodeOptions & options);

    private:
        rclcpp::Client<turtlesim::srv::TeleportAbsolute>::SharedPtr teleport_cli;
        rclcpp::Service<software_training_assignment::srv::ExampleService>::SharedPtr teleport_srv;

        void reset_moving_turtle(
            const std::shared_ptr<software_training_assignment::srv::ExampleService::Request> request,
            std::shared_ptr<software_training_assignment::srv::ExampleService::Response> response);
};
}

#endif