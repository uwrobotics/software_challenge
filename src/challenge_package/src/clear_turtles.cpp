#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "turtlesim/srv/kill.hpp"
#include "challenge_package/msg/names.hpp"

using std::placeholders::_1;

class KillTurtlesSubscriber : public rclcpp::Node 
{
  public:
    KillTurtlesSubscriber()
    : Node("kill_turtle_subscriber")
    {
      client = create_client<turtlesim::srv::Kill>("/kill");
      subscription_ = this->create_subscription<challenge_package::msg::Names>(
      "kill_turtles", 10, std::bind(&KillTurtlesSubscriber::topic_callback, this, _1));
    }

  private:
    rclcpp::Client<turtlesim::srv::Kill>::SharedPtr client;
    void topic_callback(const challenge_package::msg::Names& msg) const
    {     
      for (unsigned int i = 0; i < sizeof(msg); i++) {
        const std::string name = msg.names[i];
        
        // auto is for typing anything with a complex type
        auto kill_req = std::make_shared<turtlesim::srv::Kill::Request>();
        kill_req->name = name;
        auto res = client->async_send_request(kill_req);

        RCLCPP_INFO(this->get_logger(), "Killed Turtle: '%s'", name.c_str());
      }
    }
    rclcpp::Subscription<challenge_package::msg::Names>::SharedPtr subscription_; // sharedptr will share stuff by memory, but no big advantage (allegedly)
    
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<KillTurtlesSubscriber>());
  rclcpp::shutdown();
  return 0;
}