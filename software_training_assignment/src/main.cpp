/*
The main client for the node 
*/

#include <ros/ros.h>
#include <string>

//Service for turtlesim spawn 
#include <turtlesim/Spawn.h> 

//Service to clear the turtles 
//(I am guessing it clears the turtles)
//Based on the wording of the documentation
#include <std_srvs/Empty.h> 

int main(int argc, char **argv) {
    ros::init(argc, argv, "main"); 
    ros::NodeHandle nh; 

    //Create Client object for the spawn service
    ros::ServiceClient spawnClient = nh.ServiceClient <turtlesim::Spawn>("spawn");

    //Create the spawn request response objects 
    turtlesim::Spawn::Request spawn_req; 
    turtlesim::Spawn::Response spawn_resp; 

    //All values to be passed into the service
    int x_coords[2] = {5, 25}; 
    int y_coords[2] = {5, 10};
    string turtlenames[2] = {"stationary_turtle", "moving_turtle"}; 
    
    //Spawns all turtles
    for(int idx = 0; 0 < 2; idx++){
        //Fill the request data members
        spawn_req.x = x_coords[idx]; 
        spawn_req.y = y_coords[idx]; 
        spawn_req.theta = M_PI/2;
        spawn_req.name = turtlenames[idx]; 

        //Calls the service, waits for the return
        bool spawnSuccess = spawnClient.call(spawn_req, spawn_resp);

        //Checks if the service call was successful
        if(spawnSuccess) {
            ROS_INFO_STREAM("Spawned turtle: " << spawn_resp.name);
        } else {
            ROS_ERROR_STREAM("Failed to spawn");
        }
    }
}