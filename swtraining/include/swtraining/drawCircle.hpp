#pragma once

#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/twist.hpp>
#include <swtraining/software_training_visibility.h>

#include <chrono>
#include <cstdlib>
#include <memory>


namespace composition {

class drawCircle : public rclcpp::Node
{
    public:
        SOFTWARE_TRAINING_PUBLIC
        drawCircle(const rclcpp::NodeOptions &options);
    private:
        rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr circlePub;
        rclcpp::TimerBase::SharedPtr circleTimer;
        SOFTWARE_TRAINING_LOCAL
        void timerCB();
};
}
