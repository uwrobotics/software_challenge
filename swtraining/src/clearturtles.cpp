#include <swtraining/clearturtles.hpp>

using namespace std::chrono_literals;

namespace composition{
    clearturtles::clearturtles(const rclcpp::NodeOptions &options) : Node("clearturtles",options)
    {
        clearClient = this->create_client<turtlesim::srv::Kill>("/kill");
        clearService = this->create_service<swtraining::srv::Status>("clearturtles",std::bind(&clearturtles::clearCB,this,std::placeholders::_1,std::placeholders::_2));
        myTurtles = {"turtle1","stationary_turtle", "moving_turtle"};
    }   
    void clearturtles::clearCB(const std::shared_ptr<swtraining::srv::Status::Request> request,std::shared_ptr<swtraining::srv::Status::Response> response)
    {
        (void) request;
        while(!clearClient->wait_for_service(1s)){
            if(!rclcpp::ok()){
                RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Interrupted. Exiting");
                response->status = false;
                return;
            }
            RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Waiting...");
        }
        for(auto& turtle:myTurtles){
            auto req = std::make_unique<turtlesim::srv::Kill::Request>();
            req->name=turtle;
            auto result = clearClient->async_send_request(std::move(req));
        }  
        response->status = true;
        return;
    }
}

#include <rclcpp_components/register_node_macro.hpp>
RCLCPP_COMPONENTS_REGISTER_NODE(composition::clearturtles)