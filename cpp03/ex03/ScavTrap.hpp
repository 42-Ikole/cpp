#ifndef SCAVTRAP_H
# define SCAVTRAP_H

#include "ClapTrap.hpp"
#include <string>

class ScavTrap: public ClapTrap
{
    std::string     _enemies[3];
public:
            ScavTrap(std::string newName);
            ~ScavTrap();
            ScavTrap(const ScavTrap &tbc);
    void    operator = (const ScavTrap &tbc);
    void    challengeNewcomer();
    std::string getName(void) const;
};

#endif
