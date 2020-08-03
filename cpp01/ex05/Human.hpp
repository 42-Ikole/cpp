
#ifndef HUMAN_H
# define HUMAN_H

#include <string>
#include "Brain.hpp"

class Human
{
public:
    Brain       brain;
    std::string name;
    int         age;
    std::string identify();
};

#endif