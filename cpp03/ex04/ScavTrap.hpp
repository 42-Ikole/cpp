#ifndef SCAVTRAP_H
# define SCAVTRAP_H

#include "ClapTrap.hpp"
#include <string>

class ScavTrap: public ClapTrap
{
private:
    std::string     pname;
    std::string     enemies[3];
    std::string     attacks[5];
public:
            ScavTrap(std::string newName);
            ~ScavTrap();
    void    challengeNewcomer();
};

#endif
