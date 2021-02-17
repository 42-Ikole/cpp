#ifndef FRAGTRAP_H
# define FRAGTRAP_H

#include "ClapTrap.hpp"
#include <string>

class FragTrap: public ClapTrap
{
    std::string	_attacks[5];
public:
            FragTrap(std::string newName);
            ~FragTrap();
    void    vaulthunter_dot_exe(std::string const & target);
};

#endif
