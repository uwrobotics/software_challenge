#include "swtraining/resetturtle.hpp"

using namespace std::chrono_literals;

namespace composition{
    resetturtle::resetturtle(const rclcpp::NodeOptions &options): Node("reset_turtle",options)
    {
        resetClient = this->create_client<turtlesim::srv::TeleportAbsolute>("/moving_turtle/teleport_absolute");
        resetService = this->create_service<swtraining::srv::Status>("resetturtle",std::bind(&resetturtle::resetCB,this,std::placeholders::_1,std::placeholders::_2));
    }

    void resetturtle::resetCB(const std::shared_ptr<swtraining::srv::Status::Request> request,std::shared_ptr<swtraining::srv::Status::Response> response)
    {
        (void)request;
        while(!resetClient->wait_for_service(1s)){
            if(!rclcpp::ok()){
                RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Interrupted. Exiting");
                response->status = false;
                return;
            }
            RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Waiting...");
        }
        auto teleporter = std::make_shared<turtlesim::srv::TeleportAbsolute::Request>();
        teleporter->x = 25;
        teleporter->y = 10;
        teleporter->theta = 0;
        auto result = resetClient->async_send_request(teleporter);
        response->status = true;    
        return;
    }
}

#include <rclcpp_components/register_node_macro.hpp>
RCLCPP_COMPONENTS_REGISTER_NODE(composition::resetturtle)
