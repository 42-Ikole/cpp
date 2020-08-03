#ifndef HUMANA_H
# define HUMANA_H

#include <string>
#include "Weapon.hpp"

class HumanA
{
    private:
        std::string nname;
        Weapon      &nweapon;
    public:
        HumanA(std::string new_name, Weapon &new_weapon): nname(new_name), nweapon(new_weapon)
        {
            name = nname;
            this->weapon = &nweapon;
        }
		std::string name;
        Weapon      *weapon;
		void		attack();
};

#endif
