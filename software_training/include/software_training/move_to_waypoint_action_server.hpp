#pragma once

#include <chrono>
#include <cmath>

#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"
#include "turtlesim/msg/pose.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "software_training/action/waypoint.hpp"
#include "software_training/visibility_control.h"

using namespace std::chrono_literals;

namespace software_training {

class move_to_waypoint_action_server : public rclcpp::Node {

    public:
        using Waypoint = software_training::action::Waypoint;
        using GoalHandleWaypoint = rclcpp_action::ServerGoalHandle<Waypoint>;

        SOFTWARE_TRAINING_PUBLIC
        explicit move_to_waypoint_action_server(const rclcpp::NodeOptions& options);

    private:

        static constexpr float FLOAT_TOLERANCE = 0.05;
        static constexpr float LOOP_RATE_HZ = 100;

        typedef struct {
            float x;
            float y;
            float theta;
        } turtle_pose;

        turtle_pose moving_turtle_pose = {0, 0, 0};

        rclcpp_action::Server<Waypoint>::SharedPtr server;
        rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher;
        rclcpp::Subscription<turtlesim::msg::Pose>::SharedPtr moving_turtle_subscription;

        SOFTWARE_TRAINING_LOCAL
        void subscription_callback(const turtlesim::msg::Pose::SharedPtr msg);

        SOFTWARE_TRAINING_LOCAL
        rclcpp_action::GoalResponse handle_goal(const rclcpp_action::GoalUUID & uuid, std::shared_ptr<const Waypoint::Goal> goal);

        SOFTWARE_TRAINING_LOCAL
        rclcpp_action::CancelResponse handle_cancel(const std::shared_ptr<GoalHandleWaypoint> goal_handle);
        
        SOFTWARE_TRAINING_LOCAL
        void handle_accepted(const std::shared_ptr<GoalHandleWaypoint> goal_handle);

        SOFTWARE_TRAINING_LOCAL
        void execute(const std::shared_ptr<GoalHandleWaypoint> goal_handle);

        SOFTWARE_TRAINING_LOCAL
        float distance_to_point(float x, float y);
};

}
