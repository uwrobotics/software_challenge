#pragma once
#include <rclcpp/rclcpp.hpp>
#include <turtlesim/srv/spawn.hpp> 
#include <swtraining/srv/status.hpp>
#include <swtraining/software_training_visibility.h>

#include <chrono>
#include <cstdlib>
#include <memory>
#include <string>
#include <vector>

namespace composition{

class spawnturtles : public rclcpp::Node {

    public:
        SOFTWARE_TRAINING_PUBLIC
        spawnturtles(const rclcpp::NodeOptions &options);

    private:
        rclcpp::Client<turtlesim::srv::Spawn>::SharedPtr spawnClient;
        rclcpp::Service<swtraining::srv::Status>::SharedPtr spawnService;

        typedef struct params{
            float x;
            float y;
            float theta;
            std::string name;
        }params;

        std::vector<params> myTurtles;
        SOFTWARE_TRAINING_LOCAL
        void spawnCB(const std::shared_ptr<swtraining::srv::Status::Request> request,std::shared_ptr<swtraining::srv::Status::Response> response);
};
}