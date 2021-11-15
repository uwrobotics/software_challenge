#include "spawn_turtle.hpp"

using namespace std::chrono_literals;

namespace composition
{

SpawnTurtle::SpawnTurtle(const rclcpp::NodeOptions &options)
    : Node("spawn_turtle")
{
    std::this_thread::sleep_for(2s);

    RCLCPP_INFO(this->get_logger(), "HERE");

    this->srv_client = this->create_client<turtlesim::srv::Spawn>("/spawn");

    this->timer = this->create_wall_timer(std::chrono::milliseconds(50), 
        std::bind(&SpawnTurtle::spawn_turtles, this));

}

void SpawnTurtle::spawn_turtles()
{
    if (!srv_client->wait_for_service(2s)) {
        if (!rclcpp::ok()) {
        RCLCPP_ERROR(this->get_logger(), "Service was interupted - EXIT");
        return;
        }

        RCLCPP_INFO(this->get_logger(), "Waiting for service - DNE - EXIT");
    }

    std::map<std::string, std::vector<int>>::iterator it;

    for (it = turtles.begin(); it != turtles.end(); it++)
    {
        std::unique_ptr<turtlesim::srv::Spawn_Request> request = 
            std::make_unique<turtlesim::srv::Spawn_Request>();

        request->name = it->first;
        request->x = it->second[0];
        request->y = it->second[1];

        auto end = [this] (rclcpp::Client<turtlesim::srv::Spawn>::SharedFuture response)
        -> void {
            rclcpp::shutdown();
        };

        this->srv_client->async_send_request(std::move(request), end);
    }
}

}
RCLCPP_COMPONENTS_REGISTER_NODE(composition::SpawnTurtle)