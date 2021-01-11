#include <ros/ros.h>
#include <turtlesim/Pose.h>
#include <std_msgs/String.h>
#include <software_training_assignment/Position.h>
#include "killTurtles.cpp"
#include "publisher.h"
#include "resetPos.cpp"
#include "spawnTurtles.cpp"
#include "goto_action.h"


using namespace P;
using namespace A;


int main(int argc, char **argv)
{
	ros::init(argc, argv, "spawnturtle");

	ros::NodeHandle n;
	
	killTurtles(n);
	spawnTurtles(n, "stationary_turtle", 5, 5);
	spawnTurtles(n, "moving_turtle", 25, 10);

	ros::ServiceServer resetService = n.advertiseService("reset_pos", resetPos);
	
	Publisher posPublisher;
	posPublisher.pub = n.advertise<software_training_assignment::Position>("position", 1000);
	posPublisher.sub = n.subscribe("moving_turtle/pose", 1000, &Publisher::subCallback, &posPublisher);
	
	GotoAction goTo("goto");
	goTo.node = n;
	goTo.pub = n.advertise<geometry_msgs::Twist>("moving_turtle/cmd_vel", 1000);
	goTo.sub = n.subscribe("moving_turtle/pose", 1000, &GotoAction::subCallback, &goTo);

	ros::Rate loop_rate(10);

	while(ros::ok())
	{	
		posPublisher.publisher();	
		
		ros::spinOnce();
		
		loop_rate.sleep();	
	}

	return 0;
}
