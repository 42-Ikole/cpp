
#include <iostream>
#include <string>
#include "Zombie.hpp"

void Zombie::announce()
{
    std::cout << "\e[5m\e[1m\e[31m(" << this->type << ")\e[0m" << this->name << ": Braaiinnsss....\n";
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
