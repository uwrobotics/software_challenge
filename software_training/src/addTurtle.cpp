//This program spawns a new turtlesim turtle by calling
// the appropriate service.
#include <ros/ros.h>
//The srv class for the service.
#include <turtlesim/Spawn.h>
#include <turtlesim/Kill.h>
#include <std_srvs/Empty.h>
#include <cstdlib>
int main(int argc, char **argv){

   ros::init(argc, argv, "addTurtle");
   ros::NodeHandle nh;

//Create a client object for the spawn service. This
//needs to know the data type of the service and its name.
  
   ros::ServiceClient spawnClient
       = nh.serviceClient<turtlesim::Spawn>("spawn");
   std_srvs::Empty srv;
   srv.request;
   ros::ServiceClient reset = nh.serviceClient<std_srvs::Empty>("clear");

   ros::ServiceClient kill = nh.serviceClient<turtlesim::Kill>("kill");
   turtlesim::Kill srv2;
   srv2.request.name = "turtle1";

   reset.call(srv);
   kill.call(srv2);
//Create the request and response objects.
   turtlesim::Spawn::Request req;
   turtlesim::Spawn::Response resp;

   req.x = 5;
   req.y = 5;
   req.theta = M_PI/2;
   req.name = "stationary_turtle";

   turtlesim::Spawn::Request req2;
   turtlesim::Spawn::Response resp2;

   req2.x = 25;
   req2.y = 10;
   req2.theta = M_PI/2;
   req2.name = "moving_turtle";

   ros::service::waitForService("spawn", ros::Duration(5));
   bool success = spawnClient.call(req,resp);
   bool success2 = spawnClient.call(req2,resp2);


   if(success){
       ROS_INFO_STREAM("Spawned a turtle named "
                       << resp.name);
   }else{
       ROS_ERROR_STREAM("Failed to spawn.");
   } 
   
   if(success2){
       ROS_INFO_STREAM("Spawned a turtle named "
                       << resp2.name);
   }else{
       ROS_ERROR_STREAM("Failed to spawn.");
   }
}

