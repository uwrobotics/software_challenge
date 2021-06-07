#pragma once

#include <chrono>

#include "rclcpp/rclcpp.hpp"
#include "turtlesim/srv/teleport_absolute.hpp"
#include "software_training/srv/success.hpp"
#include "software_training/visibility_control.h"

using namespace std::chrono_literals;

namespace software_training {

class reset_moving_turtle_server : public rclcpp::Node {

    public:
        SOFTWARE_TRAINING_PUBLIC
        explicit reset_moving_turtle_server(const rclcpp::NodeOptions& options);
    
    private:
        static constexpr float START_X = 25, START_Y = 10;
        
        rclcpp::Service<software_training::srv::Success>::SharedPtr service;
        rclcpp::Client<turtlesim::srv::TeleportAbsolute>::SharedPtr teleport_turtle_client;

        // Service to reset moving_turtle to its starting position
        SOFTWARE_TRAINING_LOCAL
        void reset_moving_turtle(const std::shared_ptr<software_training::srv::Success::Request> request,
                                 std::shared_ptr<software_training::srv::Success::Response> response);
};
}
