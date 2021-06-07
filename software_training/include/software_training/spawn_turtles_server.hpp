#pragma once

#include <chrono>
#include <vector>

#include "rclcpp/rclcpp.hpp"
#include "turtlesim/srv/spawn.hpp"
#include "software_training/srv/success.hpp"
#include "software_training/visibility_control.h"

using namespace std::chrono_literals;

namespace software_training {

class spawn_turtles_server : public rclcpp::Node {

    public:
        SOFTWARE_TRAINING_PUBLIC
        explicit spawn_turtles_server(const rclcpp::NodeOptions& options);
    
    private:

        typedef struct {
            std::string name;
            float x;
            float y;
        } turtle_descriptor;
        
        std::vector<turtle_descriptor> turtle_descriptions = {
            {"stationary_turtle", 5, 5},
            {"moving_turtle", 25, 10}
        };
        
        rclcpp::Service<software_training::srv::Success>::SharedPtr service;
        rclcpp::Client<turtlesim::srv::Spawn>::SharedPtr spawn_turtle_client;

        // Service to spawn stationary_turtle and moving_turtle
        SOFTWARE_TRAINING_LOCAL
        void spawn_turtles(const std::shared_ptr<software_training::srv::Success::Request> request,
                           std::shared_ptr<software_training::srv::Success::Response> response);
};
}
