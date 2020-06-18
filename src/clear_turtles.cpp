#include <ros/ros.h>
#include <std_msgs/String.h>
#include <turtlesim/Kill.h>
int main(int argc, char **argv){

	ros::init(argc, argv, "clear_turtles");
	ros::NodeHandle n;
	ros::ServiceClient client = n.serviceClient<turtlesim::Kill>("kill");
  	turtlesim::Kill srv;
	srv.request.name = "turtle1";
	if(client.call(srv)){
		ROS_INFO("GOOD CALL");
	}else{
	 	ROS_ERROR("bad call");
		return 1;
	}
	return 0;
	
	/*
	ROS_INFO("Hello, World!");
	ros::spin();*/
}
