#include <functional>
#include <memory>
#include <thread>
#include <turtlesim/msg/pose.hpp>
#include <software_training_assingment/action/wayward.hpp>
#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"
#include "rclcpp_components/register_node_macro.hpp"
#include <chrono>
#include <geometry_msgs/msg/twist.hpp>
#include <cmath>
#include <cstdlib>



using namespace std::chrono_literals;
namespace software_training_assingment
{
class WaywardActionServer : public rclcpp::Node
{
public:
  using Wayward = software_training_assingment::action::Wayward;
  using GoalHandleWayward = rclcpp_action::ServerGoalHandle<Wayward>;

  explicit WaywardActionServer(const rclcpp::NodeOptions & options = rclcpp::NodeOptions())
  : Node("wayward_action_server", options)
  {
    using namespace std::placeholders;
    sub = this->create_subscription<turtlesim::msg::Pose>(
	"/moving_turtle/pose", 10, std::bind(&WaywardActionServer::poseCallback, this, std::placeholders::_1)); 
    this->action_server_ = rclcpp_action::create_server<Wayward>(
      this,
      "wayward",
      std::bind(&WaywardActionServer::handle_goal, this, _1, _2),
      std::bind(&WaywardActionServer::handle_cancel, this, _1),
      std::bind(&WaywardActionServer::handle_accepted, this, _1));
    pub =  this->create_publisher<geometry_msgs::msg::Twist>
        ("moving_turtle/cmd_vel",10); 
    timer_ = this->create_wall_timer(500ms, std::bind(&WaywardActionServer::startCallback, this));  

    
  }

private:
  rclcpp_action::Server<Wayward>::SharedPtr action_server_;
  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr pub;
  rclcpp::Subscription<turtlesim::msg::Pose>::SharedPtr sub;
  float curr_pose[2];
  float delta_pose[2];
  bool toggle = false;
  float norm_delta = 0;
  rclcpp_action::GoalResponse handle_goal(
    const rclcpp_action::GoalUUID & uuid,
    std::shared_ptr<const Wayward::Goal> goal)
  {
    RCLCPP_INFO(this->get_logger(), "Received goal request with pose %f  %f" , goal->x, goal->y);
    (void)uuid;
    return rclcpp_action::GoalResponse::ACCEPT_AND_EXECUTE;
  }

  rclcpp_action::CancelResponse handle_cancel(
    const std::shared_ptr<GoalHandleWayward> goal_handle)
  {
    RCLCPP_INFO(this->get_logger(), "Received request to cancel goal");
    (void)goal_handle;
    toggle = false;
    return rclcpp_action::CancelResponse::ACCEPT;
  }

  void handle_accepted(const std::shared_ptr<GoalHandleWayward> goal_handle)
  {
    using namespace std::placeholders;
    // this needs to return quickly to avoid blocking the executor, so spin up a new thread
    std::thread{std::bind(&WaywardActionServer::execute, this, _1), goal_handle}.detach();
  }
     
   void poseCallback(const turtlesim::msg::Pose::SharedPtr msg)
   {
     curr_pose[0] = msg->x;
     curr_pose[1] = msg->y;
     //RCLCPP_INFO(this->get_logger(), "Publish sub feedback %f, %f", curr_pose[0],  curr_pose[1]);
     
   
   }
   
   void startCallback()
   {
   
      if(toggle == true)
      {
             
	      auto message = geometry_msgs::msg::Twist();
	      //int time = 10;
	      
	      message.linear.x = (delta_pose[0]/norm_delta)*0.1;
	      message.linear.y = (delta_pose[1]/norm_delta)*0.1;
	      //RCLCPP_INFO(this->get_logger(), "Publish timer feedback %f, %f", message.linear.x, message.linear.y);
	      
	      pub->publish(message);
	      
      }
      
   
   
   }

  void execute(const std::shared_ptr<GoalHandleWayward> goal_handle)
  {
    RCLCPP_INFO(this->get_logger(), "Executing goal");
    //rclcpp::Rate loop_rate(1);
    const auto goal = goal_handle->get_goal();
    auto feedback = std::make_shared<Wayward::Feedback>();
    auto & distance = feedback->dist;
    auto result = std::make_shared<Wayward::Result>();
    auto x = goal->x;
    auto y = goal->y;
    delta_pose[0] = x - curr_pose[0];
    delta_pose[1] = y -curr_pose[1]; 
    norm_delta = sqrt(pow((delta_pose[0]), 2) + pow((delta_pose[1]),2));
    RCLCPP_INFO(this->get_logger(), "Executing goal %f, %f", curr_pose[0], curr_pose[1]);
    auto start = std::chrono::system_clock::now();
    RCLCPP_INFO(this->get_logger(), "Publish goal %f %f Publish curr_pose %f %f", x,y,curr_pose[0], curr_pose[1]);
    while((abs(x-curr_pose[0]) > 0.02 || abs( y - curr_pose[1]) > 0.02) && rclcpp::ok())
    {
      
      if (goal_handle->is_canceling()) {
        RCLCPP_INFO(this->get_logger(), "Goal canceled");
        return;
      }
    
    

      toggle = true;
      distance = sqrt(pow((x - curr_pose[0]), 2) + pow((y - curr_pose[1]),2));
      
      goal_handle->publish_feedback(feedback);
      //RCLCPP_INFO(this->get_logger(), "Publish feedback %f", distance);
      //RCLCPP_INFO(this->get_logger(), "Current Pose x %f  Pose y %f", curr_pose[0],curr_pose[1]);
      //rclcpp::spin(<this>);
      //loop_rate.sleep();

    }
    toggle = false;
    // Check if goal is done
    if (rclcpp::ok()) {
      auto end = std::chrono::system_clock::now();
      std::chrono::duration<double> elapsed_seconds = end - start;
      result->time = std::chrono::duration<double>(elapsed_seconds).count();
      goal_handle->succeed(result);
      RCLCPP_INFO(this->get_logger(), "Goal succeeded");
    }
  }
};  // class FibonacciActionServer

}  // namespace action_tutorials_cpp

RCLCPP_COMPONENTS_REGISTER_NODE(software_training_assingment::WaywardActionServer)


//create two timer callbcak one to set velocity based on delta x and delta y and the other to stop once it has reached its goal (maybe stop not needed we'll see)
//create sub callback to get curr position info of the moving turtle. save it as a class variable
//create a timer/stopwatch?
//distance can be obtained outside the callback function for feedback? or call sub inside the timer callback? prob the first one
//clean the damn code
