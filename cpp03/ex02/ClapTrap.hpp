#ifndef CLAPTRAP_H
# define CLAPTRAP_H

#include <string>

class ClapTrap
{
protected:
	std::string	_name;
    int         _hitPoints;
    int         _maxHitPoints;
    int         _energyPoints;
    int         _maxEnergyPoints;
    int         _level;
    int         _meleeAttackDamage;
    int         _rangedAttackDamage;
    int         _armorDamageReduction;
    std::string _attacks[5];
public:
			ClapTrap();
            ClapTrap(std::string &newName);
            ~ClapTrap();
    void	rangedAttack(std::string const & target);
    void	meleeAttack(std::string const & target);
    void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
};

#endif