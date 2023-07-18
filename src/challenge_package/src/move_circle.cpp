// Build a service for this task
// Service? Basically a gateway before a request goes to the node service

// Has a request and response?

#include "rclcpp/rclcpp.hpp"
#include <std_srvs/srv/trigger.hpp> //need to import specific hpp, then specifically refer to it
#include <geometry_msgs/msg/twist.hpp>
#include <memory>

// best practice:
// ros1 does not have components (so youd put them in namespaces - used to organize classes and definitions)
// generally always define node as a class (so I could do with just creating a class as an rclcpp node?)
using std::placeholders::_1;
using std::placeholders::_2;
using namespace std::chrono_literals;
// need to use chrono_literals to use things like "500ms"


class MoveTurtleCircularService : public rclcpp::Node
{ 
    // Why have these imports? Will find out later
    // Why trigger to define trigger service? 
    using trigger_srv = std_srvs::srv::Trigger;
    using twist_msg = geometry_msgs::msg::Twist;


    // trigger services -> template for service
    public:
      MoveTurtleCircularService(): Node("circular_motion_node") { // why does this need to be the same name?
        move_service = create_service<trigger_srv>("move_turtle1_circular", std::bind(&MoveTurtleCircularService::handle_move_req, this, _1, _2));    
        move_publisher = create_publisher<twist_msg>("turtle1/cmd_vel", 10); 
      }

    private: // difference between using std::shared_ptr

      // NEED TO SET THESE IN THE PRIVATE FROM PUBLIC
      rclcpp::Service<trigger_srv>::SharedPtr move_service;
      rclcpp::Publisher<twist_msg>::SharedPtr move_publisher;
      rclcpp::TimerBase::SharedPtr move_timer;

      void handle_move_req(
        const std::shared_ptr<trigger_srv::Request> request, std::shared_ptr<std_srvs::srv::Trigger::Response> response
      ) // do i even need the request and response if they actually arent used? Yes as its the trigger type
      {
        RCLCPP_INFO(get_logger(), "Receieved request, moving turtle");
        move_timer = create_wall_timer(500ms, std::bind(&MoveTurtleCircularService::publish_move_turtle_msg, this));
        // logic to move turtle
        // to move turtle in a circle, what needs to happen? 
        // periodically move a turtle right after x seconds


        response->success = true;
      }

      void publish_move_turtle_msg() {
        // Whats the difference between linear and angular? A: https://stackoverflow.com/questions/50976281/what-do-x-y-and-z-mean-in-geometry-msgs-twist-message-in-ros
        auto circle_msg = twist_msg();
        // circle_msg.linear.x = 1;
        circle_msg.linear.y = 1;
        // circle_msg.linear.z = 1; // doesnt matter cuz turtle only in 2D
        circle_msg.angular.x = 0;
        circle_msg.angular.y = 0;
        circle_msg.angular.z = 1; // spins around the z-axis, which would be in x and y.
        move_publisher->publish(circle_msg);
      }


};

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MoveTurtleCircularService>());
  rclcpp::shutdown();
}