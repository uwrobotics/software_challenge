#pragma once

#include "rclcpp/rclcpp.hpp"
#include "turtlesim/msg/pose.hpp"
#include "software_training/msg/distance.hpp"
#include "software_training/visibility_control.h"

using namespace std::chrono_literals;

namespace software_training {

class turtle_distance_publisher : public rclcpp::Node {

    public:
        SOFTWARE_TRAINING_PUBLIC
        explicit turtle_distance_publisher(const rclcpp::NodeOptions& options);

    private:
        rclcpp::TimerBase::SharedPtr timer;
        rclcpp::Publisher<software_training::msg::Distance>::SharedPtr publisher;
        rclcpp::Subscription<turtlesim::msg::Pose>::SharedPtr stationary_turtle_subscription;
        rclcpp::Subscription<turtlesim::msg::Pose>::SharedPtr moving_turtle_subscription;

        typedef struct {
            float x;
            float y;
        } turtle_position;

        turtle_position stationary_turtle_position = {0, 0};
        turtle_position moving_turtle_position = {0, 0};

        SOFTWARE_TRAINING_LOCAL
        void publish(void);

        SOFTWARE_TRAINING_LOCAL
        void stationary_turtle_callback(const turtlesim::msg::Pose::SharedPtr msg);
        
        SOFTWARE_TRAINING_LOCAL
        void moving_turtle_callback(const turtlesim::msg::Pose::SharedPtr msg);
};
}
