#ifndef SCAVTRAP_H
# define SCAVTRAP_H

#include "ClapTrap.hpp"
#include <string>

class ScavTrap: public ClapTrap
{
    std::string     _enemies[3];
    std::string     _attacks[5];
public:
            ScavTrap(std::string newName);
            ~ScavTrap();
    void    challengeNewcomer();
};

#endif
