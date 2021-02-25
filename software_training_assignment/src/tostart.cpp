#include "ros/ros.h"
#include "turtlesim/TeleportAbsolute.h"
#include "software_training_assignment/tostart.h"

class ToStart{
  private:
    ros::NodeHandle n;
    ros::ServiceServer service;
    float x, y, theta;

  public:
    ToStart(float x, float y, float theta) :
      x(x), y(y), theta(theta),
      service(n.advertiseService("tostart", &ToStart::tele, this)) 
    {
      ROS_INFO("Ready tostart");
      ros::spin();
    }

    bool tele(software_training_assignment::tostart::Request  &req,
         software_training_assignment::tostart::Response &res)
    {
        ros::service::waitForService("/" + req.name + "/teleport_absolute");
        ros::ServiceClient client = n.serviceClient<turtlesim::TeleportAbsolute>("/" + req.name + "/teleport_absolute");
        turtlesim::TeleportAbsolute srv;
        srv.request.x = x;
        srv.request.y = y;
        srv.request.theta = theta;

        if(client.call(srv)) {
          res.success = true;
        }
        else res.success = false;

        ROS_INFO("tostart occured");
        return true;
    }
};


int main(int argc, char **argv)
{
  ros::init(argc, argv, "toStart_server");
  ToStart toStart(5.5, 5.5, 0.0);
  return 0;
}