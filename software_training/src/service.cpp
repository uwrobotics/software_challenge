//This program spawns a new turtlesim turtle by calling
// the appropriate service.
#include <ros/ros.h>
//The srv class for the service.
#include <turtlesim/TeleportAbsolute.h>
#include <software_training/service.h>
#include "turtlesim/TeleportAbsolute.h"

/*class Service {

public:

   bool resetPosition(){
      ROS_INFO("RESET");
      return true;
   };

}*/


   bool resetPosition(software_training::ResetTurtle::Request &req, software_training::ResetTurtle::Response &res){
      ROS_INFO("RESET");
      ros::NodeHandle nh;
      turtlesim::TeleportAbsolute srv;
      srv.request.x = 20
      srv.request.y = 5
      
      client = nh.serviceClient<turtlesim::TeleportAbsolute>("moving_turtle/teleport_absolute");
      if(client.call(srv) == false){
	   return false;
	}
      return true;


      return true;
   };
int main(int argc, char **argv){
   ros::init(argc, argv, "service");
   ros::NodeHandle nh;
   
   //Service turtle;

   ros::ServiceServer reset = nh.advertise("service", resetPosition);
   
   ros::spin();
}
