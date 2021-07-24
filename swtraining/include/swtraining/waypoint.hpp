#pragma once

#include <rclcpp/rclcpp.hpp>
#include <rclcpp_action/rclcpp_action.hpp>
#include <rclcpp/time.hpp>
#include <swtraining/software_training_visibility.h>
#include <swtraining/action/waypt.hpp> 
#include <turtlesim/msg/pose.hpp>
#include <geometry_msgs/msg/twist.hpp>

#include <chrono>
#include <thread>
#include <cstdlib>
#include <cmath>

namespace composition{
    class waypoint : public rclcpp::Node {
        public:
            SOFTWARE_TRAINING_PUBLIC
            waypoint(const rclcpp::NodeOptions &options);
            using handler = rclcpp_action::ServerGoalHandle<swtraining::action::Waypt>;
        private:
            rclcpp_action::Server<swtraining::action::Waypt>::SharedPtr aserver;
            rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr pub;
            rclcpp::Subscription<turtlesim::msg::Pose>::SharedPtr sub;
            double x;
            double y;
            double theta;
            SOFTWARE_TRAINING_LOCAL
            rclcpp_action::GoalResponse handle_goal(const rclcpp_action::GoalUUID &uuid,std::shared_ptr<const swtraining::action::Waypt::Goal> goal);
            SOFTWARE_TRAINING_LOCAL
            rclcpp_action::CancelResponse handle_cancel(const std::shared_ptr<handler> goal_handle);
            SOFTWARE_TRAINING_LOCAL
            void handle_accepted(const std::shared_ptr<handler> goal_handle);
            SOFTWARE_TRAINING_LOCAL
            void execute(const std::shared_ptr<handler> goal_handle);
            SOFTWARE_TRAINING_LOCAL
            void subCB(const turtlesim::msg::Pose::SharedPtr pos);
    };
}