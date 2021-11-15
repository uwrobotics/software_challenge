#ifndef TURTLE_INFO_H
#define TURTLE_INFO_H

#include <map>
#include <vector>


std::map<std::string, std::vector<int>> turtles {
    { "moving_turtle", { 10, 10} },
    { "stationary_turtle", { 5, 5 } }
};

#endif