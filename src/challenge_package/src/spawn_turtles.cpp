// Also a service
#include "rclcpp/rclcpp.hpp"
#include <std_srvs/srv/trigger.hpp> //need to import specific hpp, then specifically refer to it
#include "turtlesim/srv/spawn.hpp"

using std::placeholders::_1;
using std::placeholders::_2;

class SpawnTurtleService : public rclcpp::Node
{
    using trigger_srv = std_srvs::srv::Trigger;

    public:
    SpawnTurtleService(): Node("spawn_turtle_node") {
        spawn_service = create_service<trigger_srv>("spawn_turtles", std::bind(&SpawnTurtleService::handle_spawn_req, this, _1, _2));
        turtlesim_client = create_client<turtlesim::srv::Spawn>("/spawn");
    }

    private:
    rclcpp::Service<trigger_srv>::SharedPtr spawn_service;
    rclcpp::Client<turtlesim::srv::Spawn>::SharedPtr turtlesim_client;

    struct Turtle {
        _Float32 x;
        _Float32 y;
        _Float32 theta;
        std::string name;
    };

    //Spawns a turtle named "stationary_turtle" at x = 5, y = 5 Spawns a second turtle named "moving_turtle" at x = 25, y = 10

    void handle_spawn_req(const std::shared_ptr<trigger_srv::Request> request, std::shared_ptr<std_srvs::srv::Trigger::Response> response)
    {
        // Establish data structure with 2 turtles
        std::vector<Turtle> turtles = {{5,5,0,"stationary_turtle"}, {25,10,0,"moving_turtle"}};
        RCLCPP_INFO(get_logger(), "Receieved request, moving turtle");
        // spawn turtles

        for (unsigned int i = 0; i < turtles.size(); i++) {
            auto spawn_req = std::make_shared<turtlesim::srv::Spawn::Request>();
            spawn_req->x = turtles[i].x;
            spawn_req->y = turtles[i].y;
            spawn_req->theta = turtles[i].theta;
            spawn_req->name = turtles[i].name;
            auto res = turtlesim_client->async_send_request(spawn_req);

            RCLCPP_INFO(this->get_logger(), "Spawned Turtle: '%s'", spawn_req->name.c_str());
        }   

        response->success = true;
    }

};

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<SpawnTurtleService>());
  rclcpp::shutdown();
}