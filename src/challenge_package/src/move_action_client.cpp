#include <memory>
#include <chrono>

#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"
#include "challenge_package/action/move.hpp"

using move_action = challenge_package::action::Move;
using goal_handle_move = rclcpp_action::ClientGoalHandle<move_action>;

class MoveActionClient : public rclcpp::Node 
{
public:
  MoveActionClient()
  : Node("move_action_client")
  {
    this->client_ptr = rclcpp_action::create_client<move_action>(
      this,
      "move_action"
    );

    // Wait for action server to be available
    while (!client_ptr->wait_for_action_server(std::chrono::seconds(5))) {
      RCLCPP_INFO(this->get_logger(), "Action server not available. Waiting...");
    }

    this->send_goal();
  }

private:
  rclcpp_action::Client<move_action>::SharedPtr client_ptr;

  void send_goal() 
  {
    auto goal_msg = move_action::Goal();
    goal_msg.x_pos = 10.0;  // For demonstration purposes
    goal_msg.y_pos = 7.5;

    RCLCPP_INFO(this->get_logger(), "Sending goal to x: %f, y: %f", goal_msg.x_pos, goal_msg.y_pos);

    auto send_goal_options = rclcpp_action::Client<move_action>::SendGoalOptions();

    send_goal_options.goal_response_callback = 
      std::bind(&MoveActionClient::goal_response_callback, this, std::placeholders::_1);

    send_goal_options.feedback_callback = 
      std::bind(&MoveActionClient::feedback_callback, this, std::placeholders::_1, std::placeholders::_2);

    send_goal_options.result_callback = 
      std::bind(&MoveActionClient::result_callback, this, std::placeholders::_1);

    this->client_ptr->async_send_goal(goal_msg, send_goal_options);
  }

  void goal_response_callback(std::shared_future<goal_handle_move::SharedPtr> future)
  {
    auto goal_handle = future.get();
    if (!goal_handle) {
      RCLCPP_ERROR(this->get_logger(), "Goal was rejected by server");
    } else {
      RCLCPP_INFO(this->get_logger(), "Goal accepted by server, waiting for result");
    }
  }

  void feedback_callback(
    goal_handle_move::SharedPtr,
    const std::shared_ptr<const move_action::Feedback> feedback)
  {
    RCLCPP_INFO(this->get_logger(), "Distance to goal: %f", feedback->distance_to_goal);
  }

  void result_callback(const goal_handle_move::WrappedResult &result)
  {
    switch(result.code) {
      case rclcpp_action::ResultCode::SUCCEEDED:
        RCLCPP_INFO(this->get_logger(), "Goal succeeded! Time taken: %f", result.result->time_taken);
        break;
      case rclcpp_action::ResultCode::ABORTED:
        RCLCPP_ERROR(this->get_logger(), "Goal was aborted");
        return;
      case rclcpp_action::ResultCode::CANCELED:
        RCLCPP_ERROR(this->get_logger(), "Goal was canceled");
        return;
      default:
        RCLCPP_ERROR(this->get_logger(), "Unknown result code");
        return;
    }
  }
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  auto client_node = std::make_shared<MoveActionClient>();
  rclcpp::spin(client_node);
  rclcpp::shutdown();
  return 0;
}