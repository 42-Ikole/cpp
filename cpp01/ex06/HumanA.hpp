#ifndef HUMANA_H
# define HUMANA_H

#include <string>
#include "Weapon.hpp"

class HumanA
{
    private:
        std::string nname;
		std::string name;
        Weapon      &nweapon;
        Weapon      *weapon;
    public:
        HumanA(std::string new_name, Weapon &new_weapon): nname(new_name), nweapon(new_weapon)
        {
            name = nname;
            this->weapon = &nweapon;
        }
		void		attack();
};

#endif
