
#ifndef HUMAN_H
# define HUMAN_H

#include <string>
#include "Brain.hpp"

class Human
{
private:
    Brain       _brain;
    std::string _name;
public:
	Brain&		getbrain();
   	std::string	identify();
};

#endif