
#include <iostream>
#include <string>
#include "Zombie.hpp"

void Zombie::announce(Zombie zombie)
{
    std::cout << "\e[5m \e[1m \e[31m(" << zombie.type << ")\e[0m" << zombie.name << ": Braaiinnsss....\n";
}
