#ifndef NINJATRAP_H
# define NINJATRAP_H

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <string>

class NinjaTrap: virtual public ClapTrap
{
private:
    std::string     pname;
public:
            NinjaTrap();
            NinjaTrap(std::string newName);
            ~NinjaTrap();
    void    ninjaShoebox(const NinjaTrap& ninja);
	void    ninjaShoebox(const ScavTrap& scav);
	void    ninjaShoebox(const FragTrap& frag);
};

#endif
