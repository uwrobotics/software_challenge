#include "ros/ros.h"
#include "software_training/reset_service.h"
#include "turtlesim/TeleportAbsolute.h"

class server{
    public:
        //callback function for server 
        bool callback(software_training::reset_service::Request& request, 
        software_training::reset_service::Response& response);
        // helper function to call moving_turtle_client - client call 
        bool moving_turtle_client();

};

bool server::callback(software_training::reset_service::Request& request, 
        software_training::reset_service::Response& response){
    response.success = (moving_turtle_client())? true : false;
    return true;
}

bool server::moving_turtle_client(){
    turtlesim::TeleportAbsolute srv; 
    srv.request.x = 5.544444561004639;
    srv.request.y = 5.544444561004639;
    srv.request.theta = 0;
    ros::NodeHandle nh; 
    ros::ServiceClient client = nh.serviceClient<turtlesim::TeleportAbsolute>
        ("/moving_turtle/teleport_absolute");
    if(client.call(srv)){
        srv.response; 
        ROS_INFO_STREAM("'moving_turtle' reseted");
        return true; 
    }
    else{
        ROS_ERROR_STREAM("the moving turtle service failed to call");
        return false; 
    }

}


int main(int argc, char ** argv){
    ros::init(argc, argv, "moving_turtle_reset_server_node");
    ros::NodeHandle nh;
    server srv_object;
    ros::ServiceServer srv = nh.advertiseService("moving_turtle_service", &server::callback, &srv_object);
    ros::spin();
    return 0;
}