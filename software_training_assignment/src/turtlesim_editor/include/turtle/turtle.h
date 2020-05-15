#include <turtlesim/Pose.h>

class turtle{
  public:
  float x;
  float y;
  float theta;
  void callback(const turtlesim::Pose::ConstPtr& msg);
};

