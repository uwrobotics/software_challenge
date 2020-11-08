/*
Server for the Reset Turtle Service
*/

#include <ros/ros.h>
#include <string> 
//Including the service files for resetTurtle service
#include <software_training_assignment/resetTurtle.h>

//Defining the service class 
class TurtleReset {
public:
    int start_x = 25; //Starting x pos for moving turtle
    int start_y = 10; //Starting y pos for moving turtle
    std::string turtle_name = "moving_turtle";
    TurtleReset() {}

    bool resetTurtlePosition(software_training_assignment::resetTurtleRequest &request, 
                            software_training_assignment::resetTurtleResponse &response){
        ROS_INFO("Turtle Position Reset"); 

        request.x = start_x; 
        request.y = start_y;
        request.name = turtle_name; 
        response.success = true; 

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
        "resetTurtle", &TurtleReset::resetTurtlePosition, &turtle); 

    ros::spin(); //Creates a infinite loop to process callbacks
    return 0; 
}