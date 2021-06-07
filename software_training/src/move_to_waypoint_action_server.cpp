#include "software_training/move_to_waypoint_action_server.hpp"

namespace software_training {

move_to_waypoint_action_server::move_to_waypoint_action_server(const rclcpp::NodeOptions& options) : rclcpp::Node("move_to_waypoint_action_server", options) {
    using namespace std::placeholders;
    this->server = rclcpp_action::create_server<Waypoint>(
        this,
        "move_to_waypoint",
        std::bind(&move_to_waypoint_action_server::handle_goal, this, _1, _2),
        std::bind(&move_to_waypoint_action_server::handle_cancel, this, _1),
        std::bind(&move_to_waypoint_action_server::handle_accepted, this, _1)
    );

    publisher = this->create_publisher<geometry_msgs::msg::Twist>("/moving_turtle/cmd_vel", 10);

    moving_turtle_subscription = this->create_subscription<turtlesim::msg::Pose>(
        "/moving_turtle/pose", 
        10, 
        std::bind(&move_to_waypoint_action_server::subscription_callback, this, _1)
    );
}

void move_to_waypoint_action_server::subscription_callback(const turtlesim::msg::Pose::SharedPtr msg) {
    moving_turtle_pose.x = msg->x;
    moving_turtle_pose.y = msg->y;
    moving_turtle_pose.theta = msg->theta;
}

rclcpp_action::GoalResponse move_to_waypoint_action_server::handle_goal(const rclcpp_action::GoalUUID & uuid, std::shared_ptr<const Waypoint::Goal> goal) {
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Received request to move to waypoint (%.3f, %3f)", goal->waypoint_x, goal->waypoint_y);
    (void)uuid;
    return rclcpp_action::GoalResponse::ACCEPT_AND_EXECUTE;
}

rclcpp_action::CancelResponse move_to_waypoint_action_server::handle_cancel(const std::shared_ptr<GoalHandleWaypoint> goal_handle) {
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Received request to cancel goal");
    (void)goal_handle;
    return rclcpp_action::CancelResponse::ACCEPT;
}

void move_to_waypoint_action_server::handle_accepted(const std::shared_ptr<GoalHandleWaypoint> goal_handle) {
    using namespace std::placeholders;
    std::thread{std::bind(&move_to_waypoint_action_server::execute, this, _1), goal_handle}.detach();
}

void move_to_waypoint_action_server::execute(const std::shared_ptr<GoalHandleWaypoint> goal_handle) {
    const auto goal = goal_handle->get_goal();
    auto feedback = std::make_shared<Waypoint::Feedback>();
    auto result = std::make_shared<Waypoint::Result>();
    float time_s = 0;

    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Moving moving_turtle to waypoint (%.3f, %.3f)", goal->waypoint_x, goal->waypoint_y);
    rclcpp::Rate loop_rate(LOOP_RATE_HZ);

    while (rclcpp::ok() && distance_to_point(goal->waypoint_x, goal->waypoint_y) > FLOAT_TOLERANCE) {
        // check if cancelling goal
        if (goal_handle->is_canceling()) {
            result->time_s = time_s;
            goal_handle->canceled(result);
            RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Goal cancelled");
            return;
        }

        // move towards waypoint: first rotate to face waypoint, then move straight
        // this is a really dumb and simple way of doing this, but it mostly works lol
        float angle_to_waypoint = atan2(goal->waypoint_y - moving_turtle_pose.y, goal->waypoint_x - moving_turtle_pose.x);
        if (std::fabs(angle_to_waypoint - moving_turtle_pose.theta) > 0.2) {
            // rotate
            auto msg = geometry_msgs::msg::Twist();
            msg.linear.x = 0;
            msg.linear.y = 0;
            msg.angular.z = 2;
            publisher->publish(msg);
        }
        else {
            // move straight
            auto msg = geometry_msgs::msg::Twist();
            msg.linear.x = 2;
            msg.linear.y = 0;
            msg.angular.z = 0;
            publisher->publish(msg);
        }

        // publish feedback
        float distance = distance_to_point(goal->waypoint_x, goal->waypoint_y);
        feedback->distance_to_waypoint = distance;
        goal_handle->publish_feedback(feedback);
        RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Distance to waypoint: %.3f", distance);

        time_s += 1/LOOP_RATE_HZ;
        loop_rate.sleep();
    }

    // check if waypoint is reached
    if (rclcpp::ok()) {
        result->time_s = time_s;
        goal_handle->succeed(result);
        RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Waypoint reached in %.3fs", time_s);
    }
}

float move_to_waypoint_action_server::distance_to_point(float x, float y) {
    return std::sqrt(std::pow(x - moving_turtle_pose.x, 2) + std::pow(y - moving_turtle_pose.y, 2));
}

}

#include "rclcpp_components/register_node_macro.hpp"

RCLCPP_COMPONENTS_REGISTER_NODE(software_training::move_to_waypoint_action_server)
