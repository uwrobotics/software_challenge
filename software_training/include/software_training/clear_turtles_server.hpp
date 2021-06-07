#pragma once

#include <chrono>
#include <vector>

#include "rclcpp/rclcpp.hpp"
#include "turtlesim/srv/kill.hpp"
#include "software_training/srv/success.hpp"
#include "software_training/visibility_control.h"

using namespace std::chrono_literals;

namespace software_training {

class clear_turtles_server : public rclcpp::Node {

    public:
        SOFTWARE_TRAINING_PUBLIC
        explicit clear_turtles_server(const rclcpp::NodeOptions& options);
    
    private:
        std::vector<std::string> TURTLE_NAMES = {"turtle1", "moving_turtle", "stationary_turtle"};
        
        rclcpp::Service<software_training::srv::Success>::SharedPtr service;
        rclcpp::Client<turtlesim::srv::Kill>::SharedPtr kill_turtles_client;

        // Service to clear all existing turtles
        SOFTWARE_TRAINING_LOCAL
        void clear_turtles(const std::shared_ptr<software_training::srv::Success::Request> request,
                           std::shared_ptr<software_training::srv::Success::Response> response);
};
}
