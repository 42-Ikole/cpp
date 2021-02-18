#ifndef FRAGTRAP_H
# define FRAGTRAP_H

#include "ClapTrap.hpp"
#include <string>

class FragTrap: virtual public ClapTrap
{
public:
            FragTrap(std::string newName);
            ~FragTrap();
            FragTrap(const FragTrap &tbc);
    std::string getName(void) const;
    void    operator = (const FragTrap &tbc);
    void    vaulthunter_dot_exe(std::string const & target);
};

#endif
