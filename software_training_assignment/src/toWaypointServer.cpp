#include "ros/ros.h"
#include "actionlib/server/simple_action_server.h"
#include "turtlesim/Pose.h"
#include "software_training_assignment/toWaypointAction.h"
#include "geometry_msgs/Twist.h"

class WaypointAction
{
  private:
    ros::NodeHandle n;
    actionlib::SimpleActionServer<software_training_assignment::toWaypointAction> as;
    std::string actionName;
    software_training_assignment::toWaypointFeedback feedback;
    software_training_assignment::toWaypointResult result;
    ros::Rate r;
    ros::Publisher velocity_publisher;
    ros::Subscriber pose_subscriber;
    turtlesim::Pose turtlesim_pose;
    float tolerance;

    static double getDistance(double x1, double y1, double x2, double y2)
    {
	    return sqrt(pow((x1-x2),2)+pow((y1-y2),2));
    }

    void executeCB(const software_training_assignment::toWaypointGoalConstPtr &goal) 
    {
      float xGoal = goal->x;
      float yGoal = goal->y;
      geometry_msgs::Twist vel_msg;
      ros::Time begin = ros::Time::now();

      vel_msg.linear.x = 0;
      vel_msg.linear.y = 0;
      vel_msg.linear.z = 0;

      do {
        double Ki = 4;
        vel_msg.angular.x = 0;
        vel_msg.angular.y = 0;
        vel_msg.angular.z = Ki*(atan2(yGoal-turtlesim_pose.y, xGoal-turtlesim_pose.x)-turtlesim_pose.theta);

        velocity_publisher.publish(vel_msg);

        ros::spinOnce();
        r.sleep();        

      } while(abs(atan2(yGoal-turtlesim_pose.y, xGoal-turtlesim_pose.x)-turtlesim_pose.theta) > tolerance);

      do {
        double Kp = 1.5;
        double Ki = 4;
        feedback.eucliDist = getDistance(turtlesim_pose.x, turtlesim_pose.y, xGoal, yGoal);
        as.publishFeedback(feedback);
        
        vel_msg.linear.x = Kp*feedback.eucliDist;
        vel_msg.linear.y = 0;
        vel_msg.linear.z = 0;
        
        vel_msg.angular.x = 0;
        vel_msg.angular.y = 0;
        vel_msg.angular.z = Ki*(atan2(yGoal-turtlesim_pose.y, xGoal-turtlesim_pose.x)-turtlesim_pose.theta);

        velocity_publisher.publish(vel_msg);

        ros::spinOnce();
        r.sleep();        

      } while(getDistance(turtlesim_pose.x, turtlesim_pose.y, xGoal, yGoal) > tolerance);

      result.deltaT = (ros::Time::now() - begin).toSec();
      vel_msg.linear.x = 0;
      vel_msg.angular.z = 0;
      velocity_publisher.publish(vel_msg);
      as.setSucceeded(result);
    }

    void poseCallback(const turtlesim::Pose::ConstPtr &pose_message)
    {
      turtlesim_pose.x = pose_message->x;
      turtlesim_pose.y = pose_message->y;
      turtlesim_pose.theta = pose_message->theta;
    }

  public:
    WaypointAction(std::string name, std::string turtle, float r, float tolerance) :
      as(n, name, boost::bind(&WaypointAction::executeCB, this, _1), false),
      actionName(name),
      velocity_publisher(n.advertise<geometry_msgs::Twist>("/" + turtle + "/cmd_vel", 1000)),
      pose_subscriber(n.subscribe("/" + turtle + "/pose", 10, &WaypointAction::poseCallback, this)),
      r(r), 
      tolerance(tolerance)
    {
      as.start();
    }

};


int main(int argc, char** argv)
{
  ros::init(argc, argv, "toWaypointServer");
  WaypointAction wa("m", "moving_turtle", 100.0, 0.01);
  ros::spin();
  return 0;
}

