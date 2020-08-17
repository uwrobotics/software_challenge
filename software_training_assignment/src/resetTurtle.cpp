/*
Server for the Reset Turtle Service
*/

#include <ros/ros.h>
#include <string> 

//Including the service files for resetTurtle service
#include <software_training_assignment/resetTurtle.h>

//Struct for the service information 
struct turtleInfo {
    std::string name; 
    int x_coord; 
    int y_coord; 
}

//Defining the service class 
class TurtleReset {
public:
    TurtleReset() {}

    bool resetTurtlePosition(software_training_assignment::resetTurtleRequest &request, 
                            software_training_assignment::resetTurtleResponse &response){
        ROS_INFO("Turtle Position Reset"); 
        return true; 
    };
}

int main(int argc, char **argv) {
    ros::init(argc, argv, "resetTurtle"); 
    ros::NodeHandle nh; 

    //Create an instance of the class
    TurtleReset turtle; 

    //Link up the service 
    ros::ServiceServer resetTurtle = nh.advertiseService(
        "resetTurtle", &TurtleReset::resetTurtlePosition, &Turtle); 

    ros::spin(); //Creates a infinite loop for the server

    return 0; 
}