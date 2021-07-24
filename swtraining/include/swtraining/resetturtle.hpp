#pragma once

#include <rclcpp/rclcpp.hpp>
#include <swtraining/srv/status.hpp>
#include <turtlesim/srv/teleport_absolute.hpp>
#include <swtraining/software_training_visibility.h>

#include <chrono>
#include <cstdlib>
#include <memory>

namespace composition {
    class resetturtle:public rclcpp::Node{
        public:
            SOFTWARE_TRAINING_PUBLIC
            resetturtle(const rclcpp::NodeOptions &options);
        private:
            rclcpp::Client<turtlesim::srv::TeleportAbsolute>::SharedPtr resetClient;
            rclcpp::Service<swtraining::srv::Status>::SharedPtr resetService;
            SOFTWARE_TRAINING_LOCAL
            void resetCB(const std::shared_ptr<swtraining::srv::Status::Request> request, std::shared_ptr<swtraining::srv::Status::Response> response);
    };       
}
