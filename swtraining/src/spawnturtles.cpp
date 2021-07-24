#include <swtraining/spawnturtles.hpp>

using namespace std::chrono_literals;

namespace composition{
    spawnturtles::spawnturtles(const rclcpp::NodeOptions &options):Node("spawn_turtles",options){
        spawnClient = this->create_client<turtlesim::srv::Spawn>("/spawn");
        spawnService = this->create_service<swtraining::srv::Status>("spawnturtles",std::bind(&spawnturtles::spawnCB,this,std::placeholders::_1,std::placeholders::_2));
        myTurtles = {
            {5,5,0,"stationary_turtle"},
            {25,10,0,"moving_turtle"}
        };
    }
    
    void spawnturtles::spawnCB(const std::shared_ptr<swtraining::srv::Status::Request> request,std::shared_ptr<swtraining::srv::Status::Response> response){
        (void) request;
        while(!spawnClient->wait_for_service(1s)){
            if(!rclcpp::ok()){
                RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Interrupted. Exiting");
                response->status = false;
                return;
            }
        RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Waiting...");
        }
        for(auto& turtle : myTurtles)
        {
            auto req = std::make_unique<turtlesim::srv::Spawn::Request>();
            req->x = turtle.x;
            req->y = turtle.y;
            req->theta = turtle.theta;
            req->name = turtle.name;
            auto result = spawnClient->async_send_request(std::move(req));  
        }
        response->status = true;
        return;
    }
}

#include<rclcpp_components/register_node_macro.hpp>
RCLCPP_COMPONENTS_REGISTER_NODE(composition::spawnturtles)