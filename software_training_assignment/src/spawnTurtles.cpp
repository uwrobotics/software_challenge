#include <turtlesim/Spawn.h>
#include "spawnTurtles.h"


bool spawnTurtles(ros::NodeHandle n, std::string name, int x, int y)
{
	ros::ServiceClient spawnClient = n.serviceClient<turtlesim::Spawn>("spawn");
	
	
	ros::service::waitForService("spawn");

	turtlesim::Spawn spawnSrv;
	
	spawnSrv.request.x = x;
	spawnSrv.request.y = y;
	spawnSrv.request.theta = 0;
	spawnSrv.request.name = name;


	if (spawnClient.call(spawnSrv))
	{
		ROS_INFO_STREAM ("Name: " << spawnSrv.response.name);	
	}
	else
	{
		ROS_ERROR("Failed to call service spawn");
		return false;
	}

	return true;
}