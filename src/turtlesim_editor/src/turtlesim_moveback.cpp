#include "ros/ros.h"
#include "turtlesim/TeleportAbsolute.h"
#include "turtlesim_editor/moveback.h"

bool moveback(turtlesim_editor::moveback::Request  &req, turtlesim_editor::moveback::Response &res)
{
    ros::NodeHandle k;
    ros::ServiceClient client= k.serviceClient<turtlesim::TeleportAbsolute>("moving_turtle/teleport_absolute");
    turtlesim::TeleportAbsolute srv;
    srv.request.x = 25;
    srv.request.y = 10;
    return(client.call(srv));
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "moveback_server");
  ros::NodeHandle n;

  ros::ServiceServer service = n.advertiseService("moveback", moveback);
  ros::spin();

  return 0;
}
