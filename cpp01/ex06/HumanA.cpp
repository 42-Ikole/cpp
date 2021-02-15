
#include <iostream>
#include "Weapon.hpp"
#include "HumanA.hpp"

HumanA::HumanA(std::string newName, Weapon &newWeapon):
    _name(newName), _weapon(&newWeapon)
{
}

void    HumanA::attack()
{
    std::cout << _name << " attacks with his " << _weapon->getType() << std::endl;
}