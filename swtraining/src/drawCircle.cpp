#include <swtraining/drawCircle.hpp>

using namespace std::chrono_literals;

namespace composition {

drawCircle::drawCircle(const rclcpp::NodeOptions &options) : Node("draw_circle",options)
{
    circlePub = this->create_publisher<geometry_msgs::msg::Twist>("turtle1/cmd_vel",1);
    circleTimer = this->create_wall_timer(5ms,std::bind(&drawCircle::timerCB,this));
}

void drawCircle::timerCB(){
    auto twist = geometry_msgs::msg::Twist();
    twist.linear.x = 1;
    twist.angular.z = 1;
    circlePub->publish(twist); 
}
}

#include <rclcpp_components/register_node_macro.hpp>
RCLCPP_COMPONENTS_REGISTER_NODE(composition::drawCircle)