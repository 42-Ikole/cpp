#include "SuperTrap.hpp"
#include <string>
#include <iostream>

SuperTrap::SuperTrap(std::string newName): name(newName)
{
	level = 1;
    std::cout << "SuperTrap constructor\n";
}

SuperTrap::~SuperTrap(){
    std::cout << "SuperTrap destructor\n";
}