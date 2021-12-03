#include "rclcpp/rclcpp.hpp"
#include <chrono>
#include <cstdlib>
#include <memory>
//#include <software_training_assingment/srv/reset_turtle.idl>     // CHANGE
#include <turtlesim/srv/teleport_absolute.hpp>
#include <software_training_assingment/srv/reset_turtle.hpp>
using std::placeholders::_1;
using std::placeholders::_2;



using namespace std::chrono_literals;

class MovRes : public rclcpp::Node
{
public:
    MovRes() : Node("reset_move")
    {
        service = this->create_service<software_training_assingment::srv::ResetTurtle>("reset_moving_turtle",
            std::bind(&MovRes::resetCallback, this, _1,_2));
            
            
        client = this->create_client<turtlesim::srv::TeleportAbsolute>("moving_turtle/teleport_absolute");
        
        
    }
    
    
    
private:
    void resetCallback(const std::shared_ptr<software_training_assingment::srv::ResetTurtle::Request> mrequest,
          std::shared_ptr<software_training_assingment::srv::ResetTurtle::Response>      mresponse)
    {
    	auto request = std::make_shared<turtlesim::srv::TeleportAbsolute::Request>();
    	request->x = 5.0;
    	request->y = 5.0;
    	RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Incoming request\na: %",
        mrequest);
   	request-> theta = 0.0;
        RCLCPP_INFO(this->get_logger(), "Request Made");
        while (!client->wait_for_service(1s)) {
	    if (!rclcpp::ok()) {
	      RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Interrupted while waiting for the service. Exiting.");
	      return;
	    }
	    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "service not available, waiting again...");
	  }

	  auto result = client->async_send_request(request);
	  mresponse->success = true;
	  RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "sending back response: []", mresponse->success);
	
    }
    
    rclcpp::Service<software_training_assingment::srv::ResetTurtle>::SharedPtr service;
    rclcpp::Client<turtlesim::srv::TeleportAbsolute>::SharedPtr client;
};

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);

  auto node = std::make_shared<MovRes>();

  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}



//create a client connection to teleport turtlesim server
//request should be name, x, y
//for the srv
	//request "True"
	//response "True or false"
