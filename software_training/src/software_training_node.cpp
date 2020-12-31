#include "ros/ros.h"
#include "turtlesim/Spawn.h"
#include "std_msgs/String.h"
#include "std_srvs/Empty.h"
#include "software_training/software_training_message.h"
#include "turtlesim/Pose.h"
#include "math.h"

class software_training_class{

    private:
        //clients
        ros::ServiceClient clientReset;
        ros::ServiceClient clientSpawn1;
        ros::ServiceClient clientMovingTurt;
        //node handles
        ros::NodeHandle nh; 
        //subscribers
        ros::Subscriber moving_turtle_pose_sub;
        ros::Subscriber stationary_turtle_pose_sub;
        //publisher
        ros::Publisher pub; 
        //publisher rate
        ros::Rate loop_rate{10};
        //turtle coordinates
        float x_moving_turtle_distance;
        float y_moving_turtle_distance;
        float x_stationary_turtle_distance;
        float y_stationary_turtle_distance; 
        
    public:
        //constructor
        software_training_class();
        //client that creates a turtle 
        void clientSpawnStationaryTurtle();
        //client that resets everything
        void clientResetTurtle();
        //client that creates moving turtle 
        void clientSpawnMovingTurtle();
        //subscriber call back for moving turtle position
        void movingTurtCallback(const turtlesim::Pose::ConstPtr& msg);
        //subscriber call back for moving turtle position
        void stationaryTurtCallback(const turtlesim::Pose::ConstPtr& msg);
        //run publisher 
        void runPublisher();
        
};

software_training_class::software_training_class(){
    clientResetTurtle();
    clientSpawnStationaryTurtle();
    clientSpawnMovingTurtle();
    //subscribers 
    moving_turtle_pose_sub = nh.subscribe("/moving_turtle/pose", 100, &software_training_class::movingTurtCallback, this);
    stationary_turtle_pose_sub = nh.subscribe("/stationary_turtle/pose", 100, &software_training_class::stationaryTurtCallback, this);        
}

void software_training_class::clientSpawnStationaryTurtle(){
    turtlesim::Spawn srv;
    srv.request.x = 5;
    srv.request.y = 5;
    srv.request.theta = 0.0;
    srv.request.name = "stationary_turtle";
    clientSpawn1 = nh.serviceClient<turtlesim::Spawn>("/spawn");
    //wait for server to exist 
    clientSpawn1.waitForExistence(ros::Duration(-1));
    if(clientSpawn1.call(srv)){
        std_msgs::String ss; 
        ss.data = srv.response.name;
        ROS_INFO("The name of the turtle %s has been spawned", ss.data.c_str());
    }
    else{
        ROS_ERROR("Failed to call '/spawn' service");
    }
}

void software_training_class::clientResetTurtle(){
    std_srvs::Empty srv; 
    // no arguments
    srv.request;
    clientReset = nh.serviceClient<std_srvs::Empty>("/clear");
    //wait for server to exit
    clientReset.waitForExistence(ros::Duration(-1));
    if(clientReset.call(srv)){
        srv.response;
        ROS_INFO_STREAM("All turtles have been cleared");
    }
    else{
        ROS_ERROR_STREAM("Failed to call '/reset' service");
    }
}

void software_training_class::clientSpawnMovingTurtle(){
    turtlesim::Spawn srv;
    srv.request.x = 25;
    srv.request.y = 10;
    srv.request.theta = 0;
    srv.request.name = "moving_turtle";
    clientMovingTurt = nh.serviceClient<turtlesim::Spawn>("/spawn");
    //wait for server existence
    clientMovingTurt.waitForExistence(ros::Duration(-1));
    if(clientMovingTurt.call(srv)){
        std_msgs::String ss;
        ss.data = srv.response.name; 
        ROS_INFO("The turtle %s has been spawned at x=%f and y=%f", ss.data.c_str(), srv.request.x, srv.request.y);
    }
    else{
        ROS_ERROR("the turtle %s has NOT been spawned", srv.request.name.c_str());
    }
}

void software_training_class::movingTurtCallback(const turtlesim::Pose::ConstPtr& msg){
    x_moving_turtle_distance = msg->x;
    y_moving_turtle_distance = msg->y;

}

void software_training_class::stationaryTurtCallback(const turtlesim::Pose::ConstPtr& msg){
    x_stationary_turtle_distance = msg->x;
    y_stationary_turtle_distance = msg->y;

}

void software_training_class::runPublisher(){
    pub = nh.advertise<software_training::software_training_message>("moving_turtle_stationary_turtle_distance",100);
    while(ros::ok()){
        //create message to be published
        software_training::software_training_message msg; 
        float abs_x_diff{abs(x_stationary_turtle_distance - x_moving_turtle_distance)};
        float abs_y_diff{abs(y_moving_turtle_distance - y_stationary_turtle_distance)};
        //fill message contents 
        msg.x_stationary_turtle_to_moving_turtle = abs_x_diff;
        msg.y_stationary_turtle_to_moving_turtle = abs_y_diff;
        msg.distance = sqrt((abs_x_diff*abs_x_diff) + (abs_y_diff*abs_y_diff));
        //actually publish message
        pub.publish(msg);
        //allow for subs to access callbacks 
        ros::spinOnce();
        loop_rate.sleep();
    }
}
int main(int argc, char **  argv){
    ros::init(argc, argv, "software_training_node");
    software_training_class node; 
    node.runPublisher();
    return 0;
}
