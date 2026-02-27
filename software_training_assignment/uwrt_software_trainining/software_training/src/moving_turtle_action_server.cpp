#include <cmath>
#include <memory>
#include <software_training/moving_turtle_action_server.hpp>

using namespace std::chrono_literals;
using namespace std::placeholders;

namespace composition {

moving_turtle_action_server::moving_turtle_action_server(
    const rclcpp::NodeOptions &options)
    : Node("moving_turtle_action_server", options) {

  // create publisher
  this->publisher = this->create_publisher<geometry_msgs::msg::Twist>(
      "/moving_turtle/cmd_vel", rclcpp::QoS(QUEUE));

  auto subscriber_callback =
      [this](const turtlesim::msg::Pose::SharedPtr msg) -> void {
    this->x = msg->x;
    this->y = msg->y;
    this->theta = msg->theta;
    this->linear_velocity = msg->linear_velocity;
    this->angular_velocity = msg->angular_velocity;
  };

  // create subscriber
  this->subscriber = this->create_subscription<turtlesim::msg::Pose>(
      "/moving_turtle/pose", QUEUE, subscriber_callback);

  // create action server
  this->action_server =
      rclcpp_action::create_server<software_training::action::Software>(
          this, "moving_turtle_action_server",
          std::bind(&moving_turtle_action_server::handle_goal, this, _1, _2),
          std::bind(&moving_turtle_action_server::handle_cancel, this, _1),
          std::bind(&moving_turtle_action_server::handle_accepted, this, _1)
      );
}

rclcpp_action::GoalResponse moving_turtle_action_server::handle_goal(
    const rclcpp_action::GoalUUID &uuid,
    std::shared_ptr<const software_training::action::Software::Goal> goal) {
  (void)uuid; // prevents compiler warnings
  RCLCPP_INFO(this->get_logger(), "Goal Received");
  return rclcpp_action::GoalResponse::ACCEPT_AND_EXECUTE;
}

rclcpp_action::CancelResponse moving_turtle_action_server::handle_cancel(
    const std::shared_ptr<GoalHandleActionServer> goal_handle) {
  (void)goal_handle; // not needed
  RCLCPP_INFO(this->get_logger(), "Received Request to cancel goal!");
  return rclcpp_action::CancelResponse::ACCEPT;
}

void moving_turtle_action_server::handle_accepted(
    const std::shared_ptr<GoalHandleActionServer> goal_handle) {
  std::thread{std::bind(&moving_turtle_action_server::execute, this, _1),
              goal_handle}
      .detach();
}

void moving_turtle_action_server::execute(
    const std::shared_ptr<GoalHandleActionServer> goal_handle) {


  rclcpp::Time start_time = this->now();
  RCLCPP_INFO(this->get_logger(), "Executing Goal");
  rclcpp::Rate cycle_rate{10};

  const auto goal = goal_handle->get_goal();
  auto result = std::make_shared<software_training::action::Software::Result>();

  float &curr_x = feedback->x_pos;
  float &curr_y = feedback->y_pos;
  float &curr_theta = feedback->theta_pos;

  // track physical distance

  float target_x = goal->linear_pos.x;
  float target_y = goal->linear_pos.y;
  float distance_to_goal = 100.0f;

  while (rclcpp::ok() && distance_to_goal > 0.1f) {
    // here we update euclidian distance 
    distance_to_goal = std::sqrt(std::pow(target_x - this->x, 2) + std::pow(target_y - this->y, 2));

    // check if goal has been reached 
    if (goal_handle->is_canceling()) {
      RCLCPP_INFO(this->get_logger(), "Goal Canceled");
      rclcpp::Duration time = this->now() - start_time;
      result->duration = static_cast<uint64_t>(time.nanoseconds());
      goal_handle->canceled(std::move(result));
      return;
    }

    // create message
    auto message_cmd_vel = std::make_unique<geometry_msgs::msg::Twist>();

    float angle_to_target = std::atan2(target_y - this->y, target_x - this->x);
    float angle_error = angle_to_target - this->theta;

    // normalize angle to prevent wild spinning
    while (angle_error > M_PI) 
      angle_error -= 2.0f * M_PI;
    while (angle_error < -M_PI) 
      angle_error += 2.0f * M_PI;

    message_cmd_vel->linear.x = 1.0f * distance_to_goal;
    message_cmd_vel->angular.z = 4.0f * angle_error;

    // publish message
    this->publisher->publish(std::move(message_cmd_vel));

    // compute feedback
    auto feedback_msg = std::make_shared<software_training::action::Software::Feedback>();
    feedback_msg->x_pos = distance_to_goal; 
    feedback_msg->y_pos = 0.0f;
    feedback_msg->theta_pos = angle_error;
    
    goal_handle->publish_feedback(feedback_msg);

    cycle_rate.sleep();
  } // brutal problem

  // stop when loop stops
  auto stop_msg = std::make_unique<geometry_msgs::msg::Twist>();
  this->publisher->publish(std::move(stop_msg));

  if (rclcpp::ok()) {
    rclcpp::Duration duration = this->now() - start_time;
    result->duration = static_cast<uint64_t>(duration.nanoseconds());
    goal_handle->succeed(std::move(result));
    RCLCPP_INFO(this->get_logger(), "Finish Executing Goal");
  }
}

} // namespace composition

#include <rclcpp_components/register_node_macro.hpp>
RCLCPP_COMPONENTS_REGISTER_NODE(composition::moving_turtle_action_server)