#include <swtraining/waypoint.hpp>

using namespace std::chrono_literals;

namespace composition {
    
    waypoint::waypoint(const rclcpp::NodeOptions& options): Node("waypoint",options){
        pub = this->create_publisher<geometry_msgs::msg::Twist>("/moving_turtle/cmd_vel",10);
        sub = this->create_subscription<turtlesim::msg::Pose>("/moving_turtle/pose",10,std::bind(&waypoint::subCB,this,std::placeholders::_1));
        aserver = rclcpp_action::create_server<swtraining::action::Waypt>(this,"waypoint",
        std::bind(&waypoint::handle_goal,this,std::placeholders::_1,std::placeholders::_2),
        std::bind(&waypoint::handle_cancel, this,std::placeholders::_1),
        std::bind(&waypoint::handle_accepted,this,std::placeholders::_1)
        );
    }

    void waypoint::subCB(const turtlesim::msg::Pose::SharedPtr pos){
        x = pos->x;
        y = pos->y;
        theta = pos->theta;
    }

    rclcpp_action::GoalResponse waypoint::handle_goal(const rclcpp_action::GoalUUID &uuid,std::shared_ptr<const swtraining::action::Waypt::Goal> goal){
        (void) goal;
        (void) uuid;
        return rclcpp_action::GoalResponse::ACCEPT_AND_EXECUTE;
    }

    rclcpp_action::CancelResponse waypoint::handle_cancel(const std::shared_ptr<handler> goal_handle){
        (void) goal_handle;
        return rclcpp_action::CancelResponse::ACCEPT;
    }

    void waypoint::handle_accepted(const std::shared_ptr<handler> goal_handle){
        std::thread{std::bind(&waypoint::execute, this, std::placeholders::_1),goal_handle}.detach();
    }

    void waypoint::execute(const std::shared_ptr<handler> goal_handle){
        rclcpp::Time t0 = this->now();
        rclcpp::Rate cycle_rate{1};
        const auto goal = goal_handle->get_goal();
        auto feedback = std::make_shared<swtraining::action::Waypt::Feedback>();
        auto res = std::make_shared<swtraining::action::Waypt::Result>();
        double tol = 0.3;
        auto twist = geometry_msgs::msg::Twist();
        while(rclcpp::ok()){
            if(goal_handle->is_canceling()){
                rclcpp::Time t1 = this->now();
                rclcpp::Duration time = t1 - t0;
                long int duration{time.nanoseconds()};
                res->wtime = duration;
                return;
            }

            
            if(fabs(atan2(goal->y - y, goal->x - x) - theta)>tol){
                twist.angular.z = 0.5*(atan2(goal->y - y, goal->x - x) - theta);
                twist.linear.x = 0;
                pub->publish(twist);
                feedback->dist = sqrt(pow(x - goal->x,2) + pow(y- goal->y,2));
                goal_handle->publish_feedback(feedback);
                cycle_rate.sleep();
            }
            
            else if(sqrt(pow(x - goal->x,2) + pow(y- goal->y,2))>0.7){
                twist.linear.x = 1;
                twist.angular.z = 0;
                pub->publish(twist);
                feedback->dist = sqrt(pow(x - goal->x,2) + pow(y- goal->y,2));
                goal_handle->publish_feedback(feedback);
                cycle_rate.sleep();
            }
            else
                break;
            
        }
        if(rclcpp::ok()){
            rclcpp::Time t1 = this->now();
            rclcpp::Duration duration = t1-t0;
            long int dt{duration.nanoseconds()};
            res->wtime = dt;
            goal_handle->succeed(res);
        }
        return;
    }
}
#include <rclcpp_components/register_node_macro.hpp>
RCLCPP_COMPONENTS_REGISTER_NODE(composition::waypoint)