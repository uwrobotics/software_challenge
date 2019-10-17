#include "ros/ros.h"
#include <cmath>										
#include "turtlesim/Pose.h"												
										
// Function declarations
void CurPose1Callback(const turtlesim::Pose::ConstPtr& msg);
void CurPose2Callback(const turtlesim::Pose::ConstPtr& msg);

// Global variables
bool STOP = true;														
turtlesim::Pose CurPose1;												
turtlesim::Pose CurPose2;											

int main(int argc, char **argv)
{
	ros::init(argc, argv, "TurtleMsg_pub1");		
	ros::NodeHandle n;													
	
	// register sub to get current stationary_turtle/pose
	ros::Subscriber CurPose1_sub = n.subscribe("/stationary_turtle/pose", 5, CurPose1Callback);
        // register sub to get current moving_turtle/pose
	ros::Subscriber CurPose2_sub = n.subscribe("/moving_turtle/pose", 5, CurPose2Callback);
	
	ros::Rate loop_rate(1);        											
	
	ROS_INFO("Ready to send position commands");					

	while (ros::ok())										
	{
		ros::spinOnce();
		if (STOP == false)												
		{
			printf("Processing...\n");
		}
		else
		{
                        //print x, y and rel distances
                        ROS_INFO("x = %.2f, y= %.2f, rel=%.2f\n", CurPose1.x - CurPose2.x, CurPose1.y - CurPose2.y, std::sqrt(std::pow(CurPose1.x - CurPose2.x, 2) + std::pow(CurPose1.y - CurPose2.y, 2)));
                        
		}
		loop_rate.sleep();												
	}
}

// call back to send new current Pose msgs
void CurPose1Callback(const turtlesim::Pose::ConstPtr& msg)			
{
	CurPose1.x = msg->x;
	CurPose1.y = msg->y;										
	return;
}

// call back to send new current Pose msgs
void CurPose2Callback(const turtlesim::Pose::ConstPtr& msg)			
{
	CurPose2.x = msg->x;
	CurPose2.y = msg->y;										
	return;
}


