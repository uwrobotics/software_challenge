#include <chrono>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "motion_interfaces/msg/turtle_distance.hpp"     // CHANGE
#include "turtlesim/msg/pose.hpp" 

#include <cmath>
#include <string>

using namespace std::chrono_literals;
using std::placeholders::_1;

class DistancePublisher : public rclcpp::Node{
    public:
        DistancePublisher(int dt, std::string pose1_topic, std::string pose2_topic) : Node("distance_publisher") {
            pose1_ = this->create_subscription<turtlesim::msg::Pose>(pose1_topic, 10, std::bind(&DistancePublisher::pose1Callback, this, _1));
            pose2_ = this->create_subscription<turtlesim::msg::Pose>(pose2_topic, 10, std::bind(&DistancePublisher::pose2Callback, this, _1));

            publisher_ = this->create_publisher<motion_interfaces::msg::TurtleDistance>("distance", 10);
            timer_ = this->create_wall_timer(
                std::chrono::milliseconds(dt), std::bind(&DistancePublisher::timer_callback, this)
                );
        }

    private:
        // Pose 1 Subscription
        rclcpp::Subscription<turtlesim::msg::Pose>::SharedPtr pose1_;
        float pose1_X = 0;
        float pose1_Y = 0;
        // Pose 2 Subscription
        rclcpp::Subscription<turtlesim::msg::Pose>::SharedPtr pose2_;
        float pose2_X = 0;
        float pose2_Y = 0;

        // Publisher
        rclcpp::Publisher<motion_interfaces::msg::TurtleDistance>::SharedPtr publisher_;
        rclcpp::TimerBase::SharedPtr timer_;

        void pose1Callback(const turtlesim::msg::Pose::SharedPtr msg){
            pose1_X = msg->x;
            pose1_Y = msg->y;
        }
        void pose2Callback(const turtlesim::msg::Pose::SharedPtr msg){
            pose2_X = msg->x;
            pose2_Y = msg->y;
        }

        void timer_callback(){
            auto message = motion_interfaces::msg::TurtleDistance();
            message.x = std::abs(pose1_X-pose2_X);
            message.y = std::abs(pose1_Y-pose2_Y);
            message.dist = sqrt(pow(pose1_X-pose2_X,2)+pow(pose1_Y-pose2_Y,2));
            
            //RCLCPP_INFO(this->get_logger(), "Publishing: dX: '%d', dY: '%d', dist: '%.2f'", message.x, message.y, message.dist);
            publisher_->publish(message);
        }
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<DistancePublisher>(500, "/moving_turtle/pose", "/stationary_turtle/pose"));
  rclcpp::shutdown();
  return 0;
}