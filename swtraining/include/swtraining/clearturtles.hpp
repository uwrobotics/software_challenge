#pragma once

#include <rclcpp/rclcpp.hpp>
#include <turtlesim/srv/kill.hpp> 
#include <swtraining/software_training_visibility.h>
#include <swtraining/srv/status.hpp>

#include <chrono>
#include <cstdlib>
#include <memory>
#include <string>
#include <vector>

namespace composition{
    class clearturtles : public rclcpp::Node{
        public:
            SOFTWARE_TRAINING_PUBLIC
            clearturtles(const rclcpp::NodeOptions & options);
        private:
            rclcpp::Client<turtlesim::srv::Kill>::SharedPtr clearClient;
            rclcpp::Service<swtraining::srv::Status>::SharedPtr clearService;
            std::vector<std::string> myTurtles;  
            SOFTWARE_TRAINING_LOCAL
            void clearCB(const std::shared_ptr<swtraining::srv::Status::Request> request,std::shared_ptr<swtraining::srv::Status::Response> response);
    };
}

