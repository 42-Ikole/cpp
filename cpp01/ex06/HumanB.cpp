
#include <iostream>
#include "Weapon.hpp"
#include "HumanB.hpp"

HumanB::HumanB(std::string newName) :
    _name(newName)
{
}

void    HumanB::attack()
{
    std::cout << _name << " attacks with his " << _weapon->getType() << std::endl;
}

void    HumanB::setWeapon(Weapon &new_weapon)
{
    _weapon = &new_weapon;
}