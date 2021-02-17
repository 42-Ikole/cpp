#ifndef NINJATRAP_H
# define NINJATRAP_H

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <string>

class NinjaTrap: public ClapTrap
{  
public:
            NinjaTrap(std::string newName);
            ~NinjaTrap();
            NinjaTrap(const NinjaTrap &tbc);
    void    operator = (const NinjaTrap &tbc);
    void    ninjaShoebox(const NinjaTrap& ninja);
	void    ninjaShoebox(const ScavTrap& scav);
	void    ninjaShoebox(const FragTrap& frag);
};

#endif
