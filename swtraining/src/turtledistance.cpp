#include "swtraining/turtledistance.hpp"

using namespace std::chrono_literals;

namespace composition{
    turtledistance::turtledistance(const rclcpp::NodeOptions &options) : Node("clearturtles",options)
    {
        distPub = this->create_publisher<swtraining::msg::Distance>("/turtledistance",10);
        distTimer = this->create_wall_timer(3s,std::bind(&turtledistance::timerCB,this));
        stSub = this->create_subscription<turtlesim::msg::Pose>("/stationary_turtle/pose",10,std::bind(&turtledistance::stCB,this,std::placeholders::_1));
        mtSub = this->create_subscription<turtlesim::msg::Pose>("/moving_turtle/pose",10,std::bind(&turtledistance::mtCB,this,std::placeholders::_1));
        mtx = 0;
        mty = 0;
        stx = 0;
        sty = 0;
    }   
    void turtledistance::timerCB()
    {
      auto message = swtraining::msg::Distance();
      message.x = fabs(stx - mtx);
      message.y = fabs(sty - mty);
      message.distance = sqrt(pow(stx - mtx,2)+pow(sty - mty,2));
      distPub->publish(message);
      return;
    }
    void turtledistance::stCB(const turtlesim::msg::Pose::SharedPtr res)
    {
        stx = res->x;
        sty = res->y;
        return;
    }
    void turtledistance::mtCB(const turtlesim::msg::Pose::SharedPtr res)
    {
        mtx = res->x;
        mty = res->y;
        return;
    } 
}

#include <rclcpp_components/register_node_macro.hpp>
RCLCPP_COMPONENTS_REGISTER_NODE(composition::turtledistance)