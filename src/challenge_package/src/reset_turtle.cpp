// Also a service
#include "rclcpp/rclcpp.hpp"
#include <std_srvs/srv/trigger.hpp> //need to import specific hpp, then specifically refer to it
#include "turtlesim/srv/teleport_absolute.hpp"

using std::placeholders::_1;
using std::placeholders::_2;

// move these to a central file and import
struct Position {
  float x;
  float y;
  float theta;
};

struct Turtle {
  _Float32 x;
  _Float32 y;
  _Float32 theta;
  std::string name;
};
class ResetTurtleService : public rclcpp::Node
{
    using trigger_srv = std_srvs::srv::Trigger;

    public:
    ResetTurtleService(): Node("reset_turtle_node") {
        reset_service = create_service<trigger_srv>("reset_moving_turtle", std::bind(&ResetTurtleService::handle_reset_req, this, _1, _2));
        turtlesim_client = create_client<turtlesim::srv::TeleportAbsolute>("/moving_turtle/teleport_absolute"); // client to call specific route for the turtlesim service
    }

    private:
    rclcpp::Service<trigger_srv>::SharedPtr reset_service;
    rclcpp::Client<turtlesim::srv::TeleportAbsolute>::SharedPtr turtlesim_client;
    Position  init_pos = {5,5,0};

    void handle_reset_req(const std::shared_ptr<trigger_srv::Request> request, std::shared_ptr<std_srvs::srv::Trigger::Response> response)
    {
      RCLCPP_INFO(get_logger(), "Receieved request, resetting turtle");
        // spawn turtles

      auto reset_req = std::make_shared<turtlesim::srv::TeleportAbsolute::Request>();
      reset_req->x = init_pos.x;
      reset_req->y = init_pos.y;
      reset_req->theta = init_pos.theta;
      auto res = turtlesim_client->async_send_request(reset_req);
      response->success = true;
      response->message = "Position reset";
      return;
    }

};

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<ResetTurtleService>());
  rclcpp::shutdown();
}