#ifndef SCAVTRAP_H
# define SCAVTRAP_H

#include <string>
#include <fstream>

class ScavTrap
{
private:
    std::string     _name;
    int             _hitPoints;
    int             _maxHitPoints;
    int             _energyPoints;
    int             _maxEnergyPoints;
    int             _level;
    int             _meleeAttackDamage;
    int             _rangedAttackDamage;
    int             _armorDamageReduction;
    std::string     _enemies[3];
    std::string     _attacks[5];
public:
            ScavTrap(std::string newName);
            ~ScavTrap();
    void	rangedAttack(std::string const & target);
    void	meleeAttack(std::string const & target);
    void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
    void    challengeNewcomer();
};

#endif
