#ifndef HUMANA_H
# define HUMANA_H

#include <string>
#include "Weapon.hpp"

class HumanA
{
    private:
		std::string _name;
        Weapon      *_weapon;
    public:
        HumanA(std::string newName, Weapon &newWeapon);
		void		attack();
};

#endif
