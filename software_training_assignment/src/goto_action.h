#include <software_training_assignment/GotoAction.h>
#include <actionlib/server/simple_action_server.h>
#include <turtlesim/Pose.h>
#include <geometry_msgs/Twist.h>

namespace A
{
    class GotoAction
    {
    	public:
    		ros::NodeHandle node;
    		GotoAction(std::string name) : as_(node, name, boost::bind(&GotoAction::executeCB, this, _1), false)
	    	{
	    		as_.start();
				ROS_INFO("Action server started");
	    	}

	    	~GotoAction(void)
	    	{
	    	}

	    	ros::Publisher pub;
	    	ros::Subscriber sub;
	    	double x, y;
    
	    	void subCallback(const turtlesim::Pose::ConstPtr& msg)
	    	{
		    	x = msg->x;
		    	y = msg->y;
	    	}

	    	void executeCB(const software_training_assignment::GotoGoal::ConstPtr &goal)
	    	{
			
				ROS_INFO("executeCB called");
		    	double relativeX = goal->x - x,
		    	       relativeY = goal->y - y,
		            	relativeDist = sqrt(pow(relativeX, 2) + pow(relativeY, 2)),
		    		theta = acos(relativeX / relativeDist);

				if (relativeY < 0)
					theta *= -1;

		    	bool success = true;

		    	geometry_msgs::Twist rotation;

		    	feedback_.distance = relativeDist;
		    	as_.publishFeedback(feedback_);
			
			    rotation.angular.z = theta;

		    	pub.publish(rotation);

				ros::Duration(1).sleep();

		    	double gotoCount = (int)relativeDist / 2, gotoRe = relativeDist - (gotoCount * 2);
		    	ros::Duration gotoDuration(1);

		    	geometry_msgs::Twist forward;

		    	forward.linear.x = 2;
		    	for (int count = 0; count < gotoCount; count++)
		    	{
		    		if(as_.isPreemptRequested() || !ros::ok())
			    	{
			    		as_.setPreempted();
			    		success = false;
			    		break;
			    	}
			    	pub.publish(forward);
					ros::Duration(1).sleep();
			    	gotoDuration += ros::Duration(1);

			    }

		    	forward.linear.x = gotoRe;

		    	gotoDuration += ros::Duration(2);

			    pub.publish(forward);
				ros::Duration(1).sleep();

			    if (success)
			    {
			    	result_.time_elapsed = gotoDuration;
			    	as_.setSucceeded(result_);
		    	}

		    }
	
	    protected:
		    software_training_assignment::GotoFeedback feedback_;
			actionlib::SimpleActionServer<software_training_assignment::GotoAction> as_;
	    	software_training_assignment::GotoResult result_;
    };
}