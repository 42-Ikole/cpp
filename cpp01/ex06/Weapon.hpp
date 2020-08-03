#ifndef WEAPON_H
# define WEAPON_H

#include <string>

class Weapon
{
    private:
        std::string str;
    public:
        Weapon()
        {
            setType("knife");
        }
        Weapon(std::string weapon_type): str(weapon_type)
        {
            type = str;
        }

        std::string	        type;
        const std::string	getType();
        void		        setType(std::string new_type);
};

#endif
