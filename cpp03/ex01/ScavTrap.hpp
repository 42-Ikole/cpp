#ifndef SCAVTRAP_H
# define SCAVTRAP_H

#include <string>
#include <fstream>

class ScavTrap
{
private:
    int hitPoints;
    int maxHitPoints;
    int energyPoints;
    int maxEnergyPoints;
    int level;
    std::string name;
    int meleeAttackDamage;
    int rangedAttackDamage;
    int armorDamageReduction;
    std::ofstream   output;
    std::string enemies[3];
    std::string attacks[5];
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
