#include "move_turtle_server.hpp"

using namespace std::placeholders;
using namespace std::chrono;

namespace composition
{

MoveTurtleServer::MoveTurtleServer(const rclcpp::NodeOptions & options)
    : Node("move_turtle")
{
    RCLCPP_INFO(this->get_logger(), "MOVE");

    this->publisher = this->create_publisher<geometry_msgs::msg::Twist>("moving_turtle/cmd_vel", 10);

    this->action_server = rclcpp_action::create_server<MoveTo>(
        this,
        "move_to",
        std::bind(&MoveTurtleServer::handle_goal, this, _1, _2),
        std::bind(&MoveTurtleServer::handle_cancel, this, _1),
        std::bind(&MoveTurtleServer::handle_accepted, this, _1)
    );

    pose_sub = this->create_subscription<turtlesim::msg::Pose>("moving_turtle/pose",0, 
        std::bind(&MoveTurtleServer::get_pose, this, _1));
}

rclcpp_action::GoalResponse MoveTurtleServer::handle_goal(
    const rclcpp_action::GoalUUID & uuid,
    std::shared_ptr<const MoveTo::Goal> goal)
{
    target = goal->position;
    RCLCPP_INFO(this->get_logger(), "Received goal request with position %f, %f", target[0], target[1]);
    (void) uuid;
    return rclcpp_action::GoalResponse::ACCEPT_AND_EXECUTE;
}
    

rclcpp_action::CancelResponse MoveTurtleServer::handle_cancel(
    const std::shared_ptr<GoalHandleMoveTo> goal_handle)
{
    RCLCPP_INFO(this->get_logger(), "Received request to cancel goal");
    (void) goal_handle;
    return rclcpp_action::CancelResponse::ACCEPT;
}

void MoveTurtleServer::handle_accepted(const std::shared_ptr<GoalHandleMoveTo> goal_handle)
{
    std::thread{std::bind(&MoveTurtleServer::execute, this, _1), goal_handle}.detach();
}

void MoveTurtleServer::execute(const std::shared_ptr<GoalHandleMoveTo> goal_handle)
{
    RCLCPP_INFO(this->get_logger(), "Executing goal");
    rclcpp::Rate loop_rate(100);

    int linear_velocity = 1; //change
    RCLCPP_INFO(this->get_logger(), "Current position: %f, %f \n Target position: %f, %f", 
        curr_x, curr_y, target[0], target[1]);

    
    auto msg = geometry_msgs::msg::Twist();
    msg.linear.x = (target[0] - curr_x) * linear_velocity;
    msg.linear.y = (target[1] - curr_y) * linear_velocity;
    publisher->publish(msg);

    auto feedback = std::make_shared<MoveTo::Feedback>();
    auto& distance = feedback->distance;
    auto result = std::make_shared<MoveTo::Result>();

    auto start = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();

    while (rclcpp::ok() && std::abs(curr_x-target[0] > 0.05) && std::abs(curr_y-target[1]) > 0.05)
    {
        distance = std::sqrt(std::pow(curr_x-target[0], 2) + std::pow(curr_y-target[1], 2));
        
        goal_handle->publish_feedback(feedback);
        loop_rate.sleep();
    }

    if (rclcpp::ok())
    {
        auto now = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
        result->seconds = now - start;
        goal_handle->succeed(result);
        RCLCPP_INFO(this->get_logger(), "Goal succeeded");
    }
}

void MoveTurtleServer::get_pose(const turtlesim::msg::Pose::SharedPtr currentPose)
{
    this->curr_x = currentPose->x;
    this->curr_y = currentPose->y;

    //RCLCPP_INFO(this->get_logger(), "Current position: %f, %f", curr_x, curr_y);
}

}

RCLCPP_COMPONENTS_REGISTER_NODE(composition::MoveTurtleServer)