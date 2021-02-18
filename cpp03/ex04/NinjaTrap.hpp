#ifndef NINJATRAP_H
# define NINJATRAP_H

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <string>

class NinjaTrap: virtual public ClapTrap
{  
public:
            NinjaTrap(std::string newName);
            ~NinjaTrap();
            NinjaTrap(const NinjaTrap &tbc);
    std::string getName(void) const;
    void    operator = (const NinjaTrap &tbc);
    void    ninjaShoebox(const NinjaTrap& ninja);
	void    ninjaShoebox(const ScavTrap& scav);
	void    ninjaShoebox(const FragTrap& frag);
};

#endif
