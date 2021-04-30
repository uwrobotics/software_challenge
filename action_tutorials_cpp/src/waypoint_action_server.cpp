// Copyright 2019 Open Source Robotics Foundation, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <memory>

#include "action_tutorials_interfaces/action/fibonacci.hpp"
#include "rclcpp/rclcpp.hpp"
// TODO(jacobperron): Remove this once it is included as part of 'rclcpp.hpp'
#include "rclcpp_action/rclcpp_action.hpp"
#include "rclcpp_components/register_node_macro.hpp"

#include "action_tutorials_cpp/visibility_control.h"
#include "motion_interfaces/action/go_to_waypoint.hpp"

#include <geometry_msgs/msg/twist.hpp>
#include "turtlesim/msg/pose.hpp"


namespace action_tutorials_cpp
{
class WaypointActionServer : public rclcpp::Node
{
public:
  using Waypoint = motion_interfaces::action::GoToWaypoint;
  using GoalHandleWaypoint = rclcpp_action::ServerGoalHandle<Waypoint>;

  ACTION_TUTORIALS_CPP_PUBLIC
  explicit WaypointActionServer(const rclcpp::NodeOptions & options = rclcpp::NodeOptions())
  : Node("fibonacci_action_server", options)
  {
    using namespace std::placeholders;
    RCLCPP_INFO(this->get_logger(), "Starting Waypoint Action Server 2!");

    pose_ = this->create_subscription<turtlesim::msg::Pose>("/moving_turtle/pose", 10, std::bind(&WaypointActionServer::poseCallback, this, _1));
    publisher_ = this->create_publisher<geometry_msgs::msg::Twist>("/moving_turtle/cmd_vel", 10);


    this->action_server_ = rclcpp_action::create_server<Waypoint>(
      this->get_node_base_interface(),
      this->get_node_clock_interface(),
      this->get_node_logging_interface(),
      this->get_node_waitables_interface(),
      "waypoint",
      std::bind(&WaypointActionServer::handle_goal, this, _1, _2),
      std::bind(&WaypointActionServer::handle_cancel, this, _1),
      std::bind(&WaypointActionServer::handle_accepted, this, _1));
  }

private:
  rclcpp::Subscription<turtlesim::msg::Pose>::SharedPtr pose_;
  float poseX = 0;
  float poseY = 0;
  float poseTheta = 0;
  rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher_; 
  rclcpp_action::Server<Waypoint>::SharedPtr action_server_;

  void poseCallback(const turtlesim::msg::Pose::SharedPtr msg)
  {
      poseX = msg->x;
      poseY = msg->y;
      poseTheta = msg->theta;
  } 

  ACTION_TUTORIALS_CPP_LOCAL
  rclcpp_action::GoalResponse handle_goal(
    const rclcpp_action::GoalUUID & uuid,
    std::shared_ptr<const Waypoint::Goal> goal)
  {
    RCLCPP_INFO(this->get_logger(), "Received goal request");
    (void)uuid;
    // Let's reject sequences that are over 9000
    return rclcpp_action::GoalResponse::ACCEPT_AND_EXECUTE;
  }

  ACTION_TUTORIALS_CPP_LOCAL
  rclcpp_action::CancelResponse handle_cancel(
    const std::shared_ptr<GoalHandleWaypoint> goal_handle)
  {
    RCLCPP_INFO(this->get_logger(), "Received request to cancel goal");
    (void)goal_handle;
    return rclcpp_action::CancelResponse::ACCEPT;
  }

  ACTION_TUTORIALS_CPP_LOCAL
  void handle_accepted(const std::shared_ptr<GoalHandleWaypoint> goal_handle)
  {
    using namespace std::placeholders;
    // this needs to return quickly to avoid blocking the executor, so spin up a new thread
    std::thread{std::bind(&WaypointActionServer::execute, this, _1), goal_handle}.detach();
  }

  ACTION_TUTORIALS_CPP_LOCAL
  void execute(const std::shared_ptr<GoalHandleWaypoint> goal_handle)
  {
    RCLCPP_INFO(this->get_logger(), "Executing Goal");
    rclcpp::Rate loop_rate(std::chrono::milliseconds(100));
    const auto goal = goal_handle->get_goal();
    auto feedback = std::make_shared<Waypoint::Feedback>();
    geometry_msgs::msg::Twist cmd_vel;
    auto result = std::make_shared<Waypoint::Result>();

    auto start = rclcpp::Node::now();
    float targX = goal->x;
    float targY = goal->y;

    double kP_linear = 0.5;
    double kP_angular = 2;
    double tolerance = 0.01;

    while(rclcpp::ok()){
        if(goal_handle->is_canceling()){
            auto diff = rclcpp::Node::now() - start;
            result->time = diff.seconds();

            goal_handle->canceled(result);
            RCLCPP_INFO(this->get_logger(), "Goal canceled");
            return;
        }

        float dist = getDist(targX, poseX, targY, poseY);
        float angleGoal = atan2((targY-poseY),(targX-poseX));

        if(abs(angleGoal-poseTheta) > tolerance){
            cmd_vel.angular.z = kP_angular * (angleGoal-poseTheta);
            cmd_vel.angular.x = 0;
            cmd_vel.angular.y = 0;
            cmd_vel.linear.x = 0;
            cmd_vel.linear.y = 0;
            cmd_vel.linear.z = 0;
            publisher_->publish(cmd_vel);
            feedback->dist = dist;
            goal_handle->publish_feedback(feedback);
            RCLCPP_INFO(this->get_logger(), "Reaching Angle Goal %.2f current Theta: %.2f", angleGoal, poseTheta);
            
            loop_rate.sleep();
            continue;
        }else if(dist > tolerance){
            cmd_vel.angular.z = 0;
            cmd_vel.angular.x = 0;
            cmd_vel.angular.y = 0;

            cmd_vel.linear.x = kP_linear * dist;
            cmd_vel.linear.y = 0;
            cmd_vel.linear.z = 0;

            publisher_->publish(cmd_vel);
            feedback->dist = dist;
            goal_handle->publish_feedback(feedback);
            RCLCPP_INFO(this->get_logger(), "Publish feedback");
            
            loop_rate.sleep();
            continue;
        }else{
            break;
        }
    }
    if(rclcpp::ok()){
        auto diff = rclcpp::Node::now() - start;
        result->time = diff.seconds();
        goal_handle->succeed(result);
        RCLCPP_INFO(this->get_logger(), "Goal succeeded");
    }               
  }

  static float getDist(float x1, float x2, float y1, float y2){
      return sqrt(pow(x2-x1,2) + pow(y2-y1,2));
  }  

};  // class WaypointActionServer

}  // namespace action_tutorials_cpp

RCLCPP_COMPONENTS_REGISTER_NODE(action_tutorials_cpp::WaypointActionServer)