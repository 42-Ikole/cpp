
#include <iostream>
#include "Weapon.hpp"
#include "HumanB.hpp"

void    HumanB::attack()
{
    std::cout << name << " attacks with his " << weapon->getType() << std::endl;
}

void    HumanB::setWeapon(Weapon &new_weapon)
{
    weapon = &new_weapon;
}