#include <turtlesim/Kill.h>
#include "killTurtles.h"

bool killTurtles(ros::NodeHandle n)
{
	ros::ServiceClient killClient = n.serviceClient<turtlesim::Kill>("kill");

	ros::service::waitForService("kill");

	turtlesim::Kill killSrv;
	
	killSrv.request.name = "turtle1";


	if (killClient.call(killSrv))
	{
		ROS_INFO_STREAM (killSrv.request.name << " killed");
	}
	else
	{
		ROS_ERROR("Failed to call service kill");
		return false;
	}

	return true;
}