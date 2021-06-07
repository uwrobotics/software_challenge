#pragma once

#include "rclcpp/rclcpp.hpp"
#include "turtlesim/msg/pose.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "software_training/visibility_control.h"

using namespace std::chrono_literals;

namespace software_training {

class move_turtle1_in_circle_publisher : public rclcpp::Node {

    public:
        SOFTWARE_TRAINING_PUBLIC
        explicit move_turtle1_in_circle_publisher(const rclcpp::NodeOptions& options);

    private:
        rclcpp::TimerBase::SharedPtr timer;
        rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher;

        SOFTWARE_TRAINING_LOCAL
        void publish(void);
};
}
