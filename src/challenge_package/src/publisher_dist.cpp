#include "rclcpp/rclcpp.hpp"
#include <geometry_msgs/msg/twist.hpp>
#include <turtlesim/msg/pose.hpp>
#include <memory>

using std::placeholders::_1;
using namespace std::chrono_literals;

struct Position {
  float x;
  float y;
  float theta;
};

class DistancePublisher : public rclcpp::Node
{ 
    using twist_msg = geometry_msgs::msg::Twist;
    using pose_msg = turtlesim::msg::Pose;
    Position moving_turtle_pos;
    Position static_turtle_pos;  

    // trigger services -> template for service
    public:
      DistancePublisher(): Node("distance_publisher_node") { // why does this need to be the same 
        rclcpp::SubscriptionOptions callback_options;
        callback_group = create_callback_group(rclcpp::CallbackGroupType::MutuallyExclusive);
        callback_options.callback_group = callback_group;

        //https://docs.ros.org/en/foxy/How-To-Guides/Using-callback-groups.html
        pos_subscriber_stationary = create_subscription<pose_msg>( 
          "/stationary_turtle/pose", 
          10, 
          std::bind(&DistancePublisher::get_stat_pos, this, _1), 
          callback_options);    
      

        pos_subscriber_move = create_subscription<pose_msg>(
          "/moving_turtle/pose", 
          10, 
          std::bind(&DistancePublisher::get_move_pos, this, _1), 
          callback_options);    

        dist_publisher = create_publisher<twist_msg>("/turtle_distances", 20); 
        timer = this->create_wall_timer(
    5000ms, std::bind(&DistancePublisher::get_dist, this));
      }

    private:
      rclcpp::Subscription<pose_msg>::SharedPtr pos_subscriber_stationary;
      rclcpp::Subscription<pose_msg>::SharedPtr pos_subscriber_move;
      rclcpp::Publisher<twist_msg>::SharedPtr dist_publisher;
      rclcpp::CallbackGroup::SharedPtr callback_group;
      rclcpp::TimerBase::SharedPtr timer;
      // rclcpp::TimerBase::SharedPtr move_timer;

      void get_move_pos(const pose_msg & msg) {
        moving_turtle_pos.x = msg.x;
        moving_turtle_pos.y = msg.y;
        RCLCPP_INFO(this->get_logger(), "moving_x: %f, moving_y: %f", moving_turtle_pos.x, moving_turtle_pos.y);
      }
      
      void get_stat_pos(const pose_msg & msg) {
        static_turtle_pos.x = msg.x;
        static_turtle_pos.y = msg.y;
        RCLCPP_INFO(this->get_logger(), "static_x: %f, static_y: %f", static_turtle_pos.x, static_turtle_pos.y);
      }

      void get_dist() {
        double x = std::pow((moving_turtle_pos.x - static_turtle_pos.x), 2);
        double y = std::pow((moving_turtle_pos.y - static_turtle_pos.y), 2);
        double dist = std::sqrt(x+y);
        RCLCPP_INFO(this->get_logger(), "X Dist: %f, Y Dist: %f, Total Dist: %f", x, y, dist);
        dist_publisher->publish(dist);
      }

};

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<DistancePublisher>());
  rclcpp::shutdown();
}