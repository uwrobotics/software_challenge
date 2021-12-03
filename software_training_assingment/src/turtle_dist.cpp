#include "rclcpp/rclcpp.hpp"
#include <chrono>
#include <cstdlib>
#include <memory>
//#include <software_training_assingment/srv/reset_turtle.idl>     // CHANGE
#include <turtlesim/msg/pose.hpp>
#include <software_training_assingment/msg/distance.hpp>
#include<cmath>
using std::placeholders::_1;
//using std::placeholders::_2;



using namespace std::chrono_literals;

class Dist : public rclcpp::Node
{
public:
    Dist() : Node("turt_dist")
    {
        
        
	sub_stat = this->create_subscription<turtlesim::msg::Pose>(
	"/stationary_turtle/pose", 10, std::bind(&Dist::statCallback, this, _1));
	sub_mov = this->create_subscription<turtlesim::msg::Pose>(
	"/moving_turtle/pose", 10, std::bind(&Dist::movCallback, this, _1));

        pub =  this->create_publisher<software_training_assingment::msg::Distance>
        ("/relative_distance",10); 
        timer_ = this->create_wall_timer(
      500ms, std::bind(&Dist::timer_callback, this));

        
        
    }
    
    
    
private:

   void movCallback(const turtlesim::msg::Pose::SharedPtr msg)
   {
   mov_pose[0] = msg->x;
   mov_pose[1] = msg->y;
   
   
   
   
   }
   
   
   
   void statCallback(const turtlesim::msg::Pose::SharedPtr msg)
   {
   stat_pose[0] = msg->x;
   stat_pose[1] = msg->y;
   
   
   }
   
   
   void timer_callback()
   {
      auto message = software_training_assingment::msg::Distance();
      message.x = mov_pose[0] - stat_pose[0];
      message.y = mov_pose[1] - stat_pose[1];
      message.dist = sqrt(pow((mov_pose[0] - stat_pose[0]), 2) + pow((mov_pose[1] - stat_pose[1]),2));
      
      pub->publish(message);
   
   
   }


    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<software_training_assingment::msg::Distance>::SharedPtr pub;
    rclcpp::Subscription<turtlesim::msg::Pose>::SharedPtr sub_stat;
    rclcpp::Subscription<turtlesim::msg::Pose>::SharedPtr sub_mov;
    float stat_pose[2];
    float mov_pose[2];
    
    
};

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);

  auto node = std::make_shared<Dist>();

  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}



//create a client connection to teleport turtlesim server
//request should be name, x, y
//for the srv
	//request "True"
	//response "True or false"
