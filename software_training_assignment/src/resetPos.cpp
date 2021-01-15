#include <std_srvs/Empty.h>
#include "resetPos.h"
#include "killTurtles.h"
#include "spawnTurtles.h"

bool resetPos(std_srvs::Empty::Request &req,
	      std_srvs::Empty::Response &res)
{
	ros::NodeHandle n;

	ros::ServiceClient resetClient = n.serviceClient<std_srvs::Empty>("reset");

	ros::service::waitForService("reset");

	std_srvs::Empty resetSrv;

	if (resetClient.call(resetSrv))
	{
		killTurtles(n);
		spawnTurtles(n, "stationary_turtle", 5, 5);
		spawnTurtles(n, "moving_turtle", 25, 10);
		ROS_INFO_STREAM ("Resetted");
	}
	else
	{
		ROS_ERROR("Failed to call service reset");
		return false;
	}

	return true;
}