#include <ros/ros.h>
#include <software_training_assignment/Position.h>
#include <turtlesim/Pose.h>
#include <cmath>

namespace P
{
    class Publisher
    {
	public:
		void publisher()
		{
			software_training_assignment::Position msg;
			msg.x = x - 5;
			msg.y = y - 5;
			msg.distance = sqrt(pow(msg.x, 2) + pow(msg.y, 2));
			
	//		ROS_INFO_STREAM("x:" << msg.x << " y: " << msg.y);

			pub.publish(msg);
		}
		void subCallback(const turtlesim::Pose::ConstPtr& msg)
		{
			x = msg->x;
			y = msg->y;
	//		ROS_INFO_STREAM("moving turtle x: " << x << " y: " << y);
		}
		double x = 0, y = 0;
		ros::Publisher pub;
		ros::Subscriber sub;
    };
}