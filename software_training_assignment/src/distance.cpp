#include "ros/ros.h"
#include "turtlesim/Pose.h"
#include "software_training_assignment/tDistance.h"
#include <math.h>

class DistanceServer {
  private:
    ros::NodeHandle n;
    ros::Subscriber turtle1_pose;
    ros::Subscriber turtle2_pose;
    ros::Publisher tDistPublisher;
    ros::Rate loopRate;
    float xTurtle1;
    float yTurtle1;
    float xTurtle2;
    float yTurtle2;

  public:
    void poseCallback1(const turtlesim::PoseConstPtr& msg)
    {
      xTurtle1 = msg->x;
      yTurtle1 = msg->y;
    }

    void poseCallback2(const turtlesim::PoseConstPtr& msg)
    {
      xTurtle2 = msg->x;
      yTurtle2 = msg->y;
    }

    DistanceServer(std::string turtle1, std::string turtle2, float lr) :
      turtle1_pose(n.subscribe<turtlesim::Pose>("/" + turtle1 + "/pose", 10, boost::bind(&DistanceServer::poseCallback1, this, _1))),
      turtle2_pose(n.subscribe<turtlesim::Pose>("/" + turtle2 + "/pose", 10, boost::bind(&DistanceServer::poseCallback2, this, _1))),
      tDistPublisher(n.advertise<software_training_assignment::tDistance>("turtle_distance", 1000)),
      loopRate(lr) 
    {
      while(ros::ok()) {
        software_training_assignment::tDistance msg;
        msg.xDist = xTurtle2 - xTurtle1;
        msg.yDist = yTurtle2 - yTurtle1;
        msg.eucliDist = sqrt(pow(msg.xDist, 2) + pow(msg.yDist, 2));

        tDistPublisher.publish(msg);
        ros::spinOnce();
        loopRate.sleep();
      }
    }
};


int main(int argc, char **argv)
{
  ros::init(argc, argv, "distance_node");
  DistanceServer ds("moving_turtle", "stationary_turtle", 0.5);
  return 0;
}