/*
The main client for the node 
*/

#include <ros/ros.h>
#include <string>
#include <math.h>

//Service for turtlesim spawn 
#include <turtlesim/Spawn.h> 

//Service to clear the turtles 
//(I am guessing it clears the turtles)
//Based on the wording of the documentation
#include <std_srvs/Empty.h> 

//Including our custom message
#include <software_training_assignment/turtleDistances.h> 

//Class for determining the distances between the turtles
class turtleDistance{
    public:
    int xd;
    int yd;
    int distance;
    turtleDistance(int t1_x, int t1_y, int t2_x, int t2_y){
       xd = t1_x - t2_x;
       yd = t1_y - t2_y;
       distance = sqrt(xd*xd + yd*yd); 
    }
}

int main(int argc, char **argv) {
    ros::init(argc, argv, "main"); 
    ros::NodeHandle nh; 

    // Clear Turtles \\ 

    //Create Client object for the Clear service
    ros::ServiceClient clearClient = nh.ServiceClient <turtlesim::Clear>("clear");
    //Calls the service, waits for the return
    bool clearSuccess = clearClient.call();
    //Checks if the service call was successful
        if(clearSuccess) {
            ROS_INFO_STREAM("Turtles Cleared");
        } else {
            ROS_ERROR_STREAM("Failed to clear turtles");
        }

    // Spawn Turtles \\ 

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

    turtleDistance turtleDist(x_coords[0], y_coords[0], x_coords[1], y_coords[1]); 
    //Publisher for turtle distances 
    ros::Publisher turtleDist_pub = nh.advertise<turtleDistances>("turtle_distnaces", 10); 
    turtleDist_pub.publish(turtleDist); 
}