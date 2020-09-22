
#include <iostream>
#include <string>
#include "Zombie.hpp"

void Zombie::announce(Zombie zombie)
{
    std::cout << "\e[5m \e[1m \e[31m(" << zombie.type << ")\e[0m" << zombie.name << ": Braaiinnsss....\n";
}

void Zombie::settype(std::string type)
{
	this->type = type;
}

void Zombie::setname(std::string name)
{
	this->name = name;
}


std::string Zombie::gettype(void)
{
	return(this->type);
}

std::string Zombie::getname(void)
{
	return(this->name);
}
