#include "clear_turtle.hpp"
#include <turtle_info.hpp>

namespace composition
{

ClearTurtle::ClearTurtle(const rclcpp::NodeOptions & options)
    : Node("clear_turtle_client")
{
    RCLCPP_INFO(this->get_logger(), "Here 1");

    this->client = this->create_client<turtlesim::srv::Kill>("kill");
    
    this-> timer = this->create_wall_timer(std::chrono::seconds(1), 
        std::bind(&ClearTurtle::kill_turtles, this));
}

void ClearTurtle::kill_turtles()
{
    RCLCPP_INFO(this->get_logger(), "Here 2");

    std::map<std::string, std::vector<int>>::iterator it;

    for (it = turtles.begin(); it != turtles.end(); it++)
    {
        std::unique_ptr<turtlesim::srv::Kill_Request> request = 
            std::make_unique<turtlesim::srv::Kill_Request>();

        request->name = it->first;

        auto end = [this] (rclcpp::Client<turtlesim::srv::Kill>::SharedFuture response)
        -> void {
            rclcpp::shutdown();
        };

        this->client->async_send_request(std::move(request), end);
    }  
}

}

RCLCPP_COMPONENTS_REGISTER_NODE(composition::ClearTurtle)