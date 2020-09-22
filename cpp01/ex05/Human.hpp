
#ifndef HUMAN_H
# define HUMAN_H

#include <string>
#include "Brain.hpp"

class Human
{
private:
    Brain       brain;
    std::string name;
    int         age;
public:
	Brain&		getbrain();
   	std::string	identify();
};

#endif