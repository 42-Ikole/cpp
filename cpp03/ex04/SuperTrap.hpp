#ifndef SUPERTRAP_H
# define SUPERTRAP_H

#include "FragTrap.hpp"
#include "NinjaTrap.hpp"
#include <string>

class SuperTrap: public FragTrap, public NinjaTrap
{
public:
            SuperTrap(std::string newName);
            ~SuperTrap();
            SuperTrap(const SuperTrap &tbc);
    void    operator = (const SuperTrap &tbc);
};

#endif
