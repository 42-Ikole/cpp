#ifndef SUPERTRAP_H
# define SUPERTRAP_H

#include "FragTrap.hpp"
#include "NinjaTrap.hpp"
#include <string>

class SuperTrap: public FragTrap, public NinjaTrap
{
private:
    std::string     name;
public:
    SuperTrap(std::string newName);
    ~SuperTrap();
};

#endif
