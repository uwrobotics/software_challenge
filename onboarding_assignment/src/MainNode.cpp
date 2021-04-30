#include <chrono>
#include <cstdlib>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "turtlesim/srv/spawn.hpp"
#include "turtlesim/srv/kill.hpp"
#include "motion_interfaces/msg/turtle_distance.hpp"

#include "motion_interfaces/action/go_to_waypoint.hpp"

#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"
#include "rclcpp_components/register_node_macro.hpp"

using namespace std::chrono_literals;
using std::placeholders::_1;


//TODO: Remove hardcoded waypoint
class MainNode : public rclcpp::Node{
    public: 
        using Waypoint = motion_interfaces::action::GoToWaypoint;
        using GoalHandleWaypoint = rclcpp_action::ClientGoalHandle<Waypoint>;

        MainNode() : Node("main_node"){
            this->clear();
            this->spawn("stationary_turtle", 5.0, 5.0, 0.0);
            this->spawn("moving_turtle", 7.0, 10.0, 0.0);
            distance_ = this->create_subscription<motion_interfaces::msg::TurtleDistance>("distance", 10, std::bind(&MainNode::distanceCallback, this, _1));

            this->client_ptr_ = rclcpp_action::create_client<Waypoint>(this, "waypoint");

            this->timer_ = this->create_wall_timer(
            1000ms, std::bind(&MainNode::send_goal, this));

        }

        void clear(){
            std::shared_ptr<rclcpp::Node> node = rclcpp::Node::make_shared("kill_turtle_client");
            rclcpp::Client<turtlesim::srv::Kill>::SharedPtr client = 
                node->create_client<turtlesim::srv::Kill>("/kill");

            auto request = std::make_shared<turtlesim::srv::Kill::Request>();
            request->name = "turtle1";

            while (!client->wait_for_service(1s)) {
                if (!rclcpp::ok()) {
                    RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Interrupted while waiting for the service. Exiting.");
                    return;
                }
                RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "service not available, waiting again...");
            }

            auto result = client->async_send_request(request);
            // Wait for the result.
            if (rclcpp::spin_until_future_complete(node, result) ==
                rclcpp::FutureReturnCode::SUCCESS)
            {
                RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Killed Turtle");
            } else {
                RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Failed to kill turtle");
            }
        }

        void spawn(std::string turtleName, float x, float y, float theta){
            std::shared_ptr<rclcpp::Node> node = rclcpp::Node::make_shared("spawn_turtle_client");
            rclcpp::Client<turtlesim::srv::Spawn>::SharedPtr client = 
                node->create_client<turtlesim::srv::Spawn>("/spawn");

            auto request = std::make_shared<turtlesim::srv::Spawn::Request>();
            request->name = turtleName;
            request->x = x;
            request->y = y;
            request->theta = theta;

            while (!client->wait_for_service(1s)) {
                if (!rclcpp::ok()) {
                    RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Interrupted while waiting for the service. Exiting.");
                    return;
                }
                RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "service not available, waiting again...");
            }

            auto result = client->async_send_request(request);
            // Wait for the result.
            if (rclcpp::spin_until_future_complete(node, result) ==
                rclcpp::FutureReturnCode::SUCCESS)
            {
                RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Spawned turtle %s", result.get()->name);
            } else {
                RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Failed to Spawn Turtle");
            }
        }

        private:
            rclcpp_action::Client<Waypoint>::SharedPtr client_ptr_;
            rclcpp::TimerBase::SharedPtr timer_;

            rclcpp::Subscription<motion_interfaces::msg::TurtleDistance>::SharedPtr distance_;

            void send_goal(){
                using namespace std::placeholders;
                this->timer_->cancel();

                if (!this->client_ptr_->wait_for_action_server()) {
                    RCLCPP_ERROR(this->get_logger(), "Action server not available after waiting");
                    rclcpp::shutdown();
                }

                auto goal_msg = Waypoint::Goal();
                goal_msg.x = 2;
                goal_msg.y = 2;

                RCLCPP_INFO(this->get_logger(), "Sending goal");

                auto send_goal_options = rclcpp_action::Client<Waypoint>::SendGoalOptions();

                send_goal_options.goal_response_callback =
                    std::bind(&MainNode::goal_response_callback, this, _1);
                send_goal_options.feedback_callback =
                    std::bind(&MainNode::feedback_callback, this, _1, _2);
                send_goal_options.result_callback =
                    std::bind(&MainNode::result_callback, this, _1);

                this->client_ptr_->async_send_goal(goal_msg, send_goal_options);
            }

            void goal_response_callback(std::shared_future<GoalHandleWaypoint::SharedPtr> future)
            {
                auto goal_handle = future.get();
                if (!goal_handle) {
                    RCLCPP_ERROR(this->get_logger(), "Goal was rejected by server");
                } else {
                    RCLCPP_INFO(this->get_logger(), "Goal accepted by server, waiting for result");
                }
            }
            void feedback_callback(GoalHandleWaypoint::SharedPtr, const std::shared_ptr<const Waypoint::Feedback> feedback)
            {
                std::stringstream ss;
                ss << "Curr Dist: " << feedback->dist << " ";
                RCLCPP_INFO(this->get_logger(), ss.str().c_str());
            }

            void result_callback(const GoalHandleWaypoint::WrappedResult & result)
            {
                switch (result.code) {
                case rclcpp_action::ResultCode::SUCCEEDED:
                    break;
                case rclcpp_action::ResultCode::ABORTED:
                    RCLCPP_ERROR(this->get_logger(), "Goal was aborted");
                    return;
                case rclcpp_action::ResultCode::CANCELED:
                    RCLCPP_ERROR(this->get_logger(), "Goal was canceled");
                    return;
                default:
                    RCLCPP_ERROR(this->get_logger(), "Unknown result code");
                    return;
                }
                std::stringstream ss;
                ss << "Result received: " << result.result->time << " ";
                RCLCPP_INFO(this->get_logger(), ss.str().c_str());
                rclcpp::shutdown();
            }

            void distanceCallback(const motion_interfaces::msg::TurtleDistance::SharedPtr msg) const{
                RCLCPP_INFO(this->get_logger(), "Received: dX: '%d', dY: '%d', dist: '%.1f'", msg->x, msg->y, msg->dist);
            }     
};


int main(int argc, char * argv[]){
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<MainNode>());
    rclcpp::shutdown();
    return 0;
}
