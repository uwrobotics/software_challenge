
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"

#include <turtlesim/msg/pose.hpp>
#include <geometry_msgs/msg/twist.hpp>

#include "challenge_package/common.hpp"
#include "challenge_package/action/move.hpp"

using std::placeholders::_1;
using std::placeholders::_2;

class MoveActionServer : public rclcpp::Node 
{
  using twist_msg = geometry_msgs::msg::Twist;
  using pose_msg = turtlesim::msg::Pose;
  using move_action = challenge_package::action::Move;
  using goal_handle_move = rclcpp_action::ServerGoalHandle<move_action>;
  
  
  public:
    MoveActionServer()
    : Node("move_action_service")
    {
      vel_pub = create_publisher<twist_msg>("turtle1/cmd_vel", 10);
      pose_sub = create_subscription<pose_msg>("turtle1/pose", 10, std::bind(&MoveActionServer::get_pose, this, _1));
      action_server = rclcpp_action::create_server<move_action>(this, "move_action",
      std::bind(&MoveActionServer::handle_goal, this, _1, _2),
      std::bind(&MoveActionServer::handle_cancel, this, _1),
      std::bind(&MoveActionServer::handle_accepted, this, _1)
      );
    }

  private:
    Position curr_pos;
    Position goal_pos;
    rclcpp::Publisher<twist_msg>::SharedPtr vel_pub;
    rclcpp::Subscription<pose_msg>::SharedPtr pose_sub;
    rclcpp_action::Server<move_action>::SharedPtr action_server;

    float get_euc_dist() {
      double x = std::pow((goal_pos.x - curr_pos.x), 2);
      double y = std::pow((goal_pos.y - curr_pos.y), 2);
      double dist = std::sqrt(x+y);
      RCLCPP_DEBUG(this->get_logger(), "X Dist: %f, Y Dist: %f, Total Dist: %f", x, y, dist);
      return dist;
    }

    void get_pose(const pose_msg::SharedPtr msg) {
      curr_pos.x = msg->x;
      curr_pos.y = msg->y;
    }

    rclcpp_action::GoalResponse handle_goal(const rclcpp_action::GoalUUID & uuid, std::shared_ptr<const move_action::Goal> goal) {
      RCLCPP_INFO(this->get_logger(), "Received goal request with x: %f, y: %f", goal->x_pos, goal->y_pos);
      (void)uuid;
      goal_pos.x = goal->x_pos;
      goal_pos.y = goal->y_pos;
      return rclcpp_action::GoalResponse::ACCEPT_AND_EXECUTE;
    } 

    rclcpp_action::CancelResponse handle_cancel(const std::shared_ptr<goal_handle_move> goal_handle) {
      RCLCPP_INFO(this->get_logger(), "Received request to cancel goal");
      (void)goal_handle;
      return rclcpp_action::CancelResponse::ACCEPT;
    }

    void handle_accepted(const std::shared_ptr<goal_handle_move> goal_handle)
      {
        // this needs to return quickly to avoid blocking the executor, so spin up a new thread
        std::thread{std::bind(&MoveActionServer::execute, this, _1), goal_handle}.detach();
      }

    void execute(const std::shared_ptr<goal_handle_move> goal_handle) {
      rclcpp::Time start_time = this->now();
      RCLCPP_INFO(this->get_logger(), "Executing goal request with x: %f, y: %f", goal_pos.x, goal_pos.y);

      rclcpp::Rate action_rate(1);
      auto feedback_ptr = std::make_shared<move_action::Feedback>();
      auto result_ptr = std::make_shared<move_action::Result>();

      while (rclcpp::ok() && get_euc_dist() > 0.1) {
        if (goal_handle->is_canceling()) {
          rclcpp::Time end_time = this->now();
          result_ptr->time_taken = (end_time-start_time).seconds();
          goal_handle->canceled(result_ptr);
          RCLCPP_INFO(this->get_logger(), "Goal canceled");
          return;
        }


        auto move_msg = twist_msg();
        move_msg.linear.x = (goal_pos.x - curr_pos.x)/2;
        move_msg.linear.y = (goal_pos.y - curr_pos.y)/2;
        move_msg.linear.z = 0;
        move_msg.angular.x = 0;
        move_msg.angular.y = 0;
        move_msg.angular.z = 0;

        vel_pub->publish(move_msg);


        feedback_ptr->distance_to_goal = get_euc_dist();;
        goal_handle->publish_feedback(feedback_ptr);
        // stall the main action loop before continuing
        action_rate.sleep();
      }

    // Check if goal is done 
      if (rclcpp::ok()) {
        rclcpp::Time end_time = this->now();
        result_ptr->time_taken = (end_time-start_time).seconds();
        auto move_msg = twist_msg();
        move_msg.linear.x = 0;
        move_msg.linear.y = 0;
        move_msg.linear.z = 0;
        move_msg.angular.x = 0;
        move_msg.angular.y = 0;
        move_msg.angular.z = 0;
        vel_pub->publish(move_msg);
        goal_handle->succeed(result_ptr);
        RCLCPP_INFO(this->get_logger(), "Goal succeeded");
      }
  }
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MoveActionServer>());
  rclcpp::shutdown();
  return 0;
}