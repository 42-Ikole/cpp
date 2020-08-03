#ifndef FRAGTRAP_H
# define FRAGTRAP_H

#include <string>

class FragTrap
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
    std::string	attacks[5];
public:
            FragTrap(std::string newName);
            ~FragTrap();
    void	rangedAttack(std::string const & target);
    void	meleeAttack(std::string const & target);
    void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
    void    vaulthunter_dot_exe(std::string const & target);
};

#endif
