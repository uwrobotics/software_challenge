#ifndef STATIONARY_TURTLE_H
#define STATIONARY_TURTLE_H

#include "Turtle.h"

// Singleton "stationary_turtle" class
class StationaryTurtle : public Turtle {
    public:
    	// instance accessor
        static StationaryTurtle* getInstance(ros::NodeHandle &n);
        
    private:
    	// ctor
        StationaryTurtle(ros::NodeHandle &n);
};

#endif
