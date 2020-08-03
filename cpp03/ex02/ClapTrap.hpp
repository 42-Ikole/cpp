#ifndef CLAPTRAP_H
# define CLAPTRAP_H

#include <string>

class ClapTrap
{
public:
	std::string	name;
    int hitPoints;
    int maxHitPoints;
    int energyPoints;
    int maxEnergyPoints;
    int level;
    int meleeAttackDamage;
    int rangedAttackDamage;
    int armorDamageReduction;
			ClapTrap();
            ~ClapTrap();
    void	rangedAttack(std::string const & target);
    void	meleeAttack(std::string const & target);
    void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
};

#endif