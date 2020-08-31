#ifndef DISTANCE_PUBLISHER_H
#define DISTANCE_PUBLISHER_H

#include "Turtle.h"

class DistancePublisher {
    public:
        // ctor
        DistancePublisher(ros::NodeHandle &n, Turtle* t1, Turtle* t2);
        
        // publishes distance
        void publish();

    private:
        ros::NodeHandle n_;
        
        // ros publisher
        ros::Publisher dist_pub_;

        // 2 Turtle's to compare
        Turtle* t1_;
        Turtle* t2_;
};

#endif
