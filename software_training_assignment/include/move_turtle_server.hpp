#ifndef MOVE_H
#define MOVE_H

#include "rclcpp/rclcpp.hpp"
#include "rclcpp_components/register_node_macro.hpp"
#include "rclcpp_action/rclcpp_action.hpp"

#include <turtlesim/msg/pose.hpp>
#include <geometry_msgs/msg/twist.hpp>

#include <software_training_assignment/action/move_to.hpp>

namespace composition
{
class MoveTurtleServer : public rclcpp::Node
{
    public:
        using MoveTo = software_training_assignment::action::MoveTo;
        using GoalHandleMoveTo = rclcpp_action::ServerGoalHandle<MoveTo>;

        MoveTurtleServer(const rclcpp::NodeOptions & options);

    private:
        rclcpp_action::Server<MoveTo>::SharedPtr action_server;
        rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher;
        rclcpp::Subscription<turtlesim::msg::Pose>::SharedPtr pose_sub;

        float curr_x;
        float curr_y;
        std::vector<float> target;

        rclcpp_action::GoalResponse handle_goal(const rclcpp_action::GoalUUID & uuid,
            std::shared_ptr<const MoveTo::Goal> goal);

        rclcpp_action::CancelResponse handle_cancel(const std::shared_ptr<GoalHandleMoveTo> goal_handle);
        void handle_accepted(const std::shared_ptr<GoalHandleMoveTo> goal_handle);
        void execute(const std::shared_ptr<GoalHandleMoveTo> goal_handle);
        void get_pose(const turtlesim::msg::Pose::SharedPtr currentPose);
};
}

#endif