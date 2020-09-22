#ifndef HUMANB_H
# define HUMANB_H

#include <string>
#include "Weapon.hpp"

class HumanB
{
    private:
        std::string nname;
        Weapon      *weapon;
		std::string name;
    public:
        HumanB(std::string new_name): nname(new_name)
        {
            name = nname;
        }
		void		attack();
        void        setWeapon(Weapon &new_weapon);
};

#endif
