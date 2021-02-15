
#include <string>
#include "Weapon.hpp"

Weapon::Weapon(): 
_type("Knife")
{
}

Weapon::Weapon(std::string weapon_type) :
    _type(weapon_type)
{ 
}

const std::string Weapon::getType()
{
    return (_type);
}
		
void    Weapon::setType(std::string new_type)
{
    _type = new_type;
}
