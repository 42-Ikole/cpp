
#include <iostream>
#include <string>
#include "Zombie.hpp"

void Zombie::announce(Zombie zombie)
{
    std::cout << "\e[5m\e[1m\e[31m(" << zombie._type << ")\e[0m" << zombie._name << ": Braaiinnsss....\n";
}

void Zombie::settype(std::string type)
{
	this->_type = type;
}

void Zombie::setname(std::string name)
{
	this->_name = name;
}


std::string Zombie::gettype(void)
{
	return(this->_type);
}

std::string Zombie::getname(void)
{
	return(this->_name);
}
