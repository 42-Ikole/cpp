#ifndef FRAGTRAP_H
# define FRAGTRAP_H

#include "ClapTrap.hpp"
#include <string>

class FragTrap: public ClapTrap
{
public:
            FragTrap(std::string newName);
            ~FragTrap();
            FragTrap(const FragTrap &tbc);
    void    operator = (const FragTrap &tbc);
    void    vaulthunter_dot_exe(std::string const & target);
    std::string getName(void) const;
};

#endif
