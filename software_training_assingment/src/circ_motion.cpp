#include "rclcpp/rclcpp.hpp"
#include <chrono>
#include <cstdlib>
#include <memory>
//#include <software_training_assingment/srv/reset_turtle.idl>     // CHANGE
#include <geometry_msgs/msg/twist.hpp>
#include<cmath>
using std::placeholders::_1;
//using std::placeholders::_2;



using namespace std::chrono_literals;

class Circ : public rclcpp::Node
{
public:
    Circ() : Node("circ_motion")
    {
        

        pub =  this->create_publisher<geometry_msgs::msg::Twist>
        ("turtle1/cmd_vel",10); 
        timer_ = this->create_wall_timer(
      500ms, std::bind(&Circ::timer_callback, this));

        
        
    }
    
    
    
private:   
   void timer_callback()
   {
      auto message = geometry_msgs::msg::Twist();
      message.linear.x = 0;
      message.linear.y = 4;
      message.angular.z = 2;

      
      pub->publish(message);
   
   
   }


    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr pub;
    float stat_pose[2];
    float mov_pose[2];
    
    
};

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);

  auto node = std::make_shared<Circ>();

  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}



//create a client connection to teleport turtlesim server
//request should be name, x, y
//for the srv
	//request "True"
	//response "True or false"
