#ifndef FRAGTRAP_H
# define FRAGTRAP_H

# include <string>

class FragTrap
{
private:
    std::string _name;
    int         _hitPoints;
    int         _maxHitPoints;
    int         _energyPoints;
    int         _maxEnergyPoints;
    int         _level;
    int         _meleeAttackDamage;
    int         _rangedAttackDamage;
    int         _armorDamageReduction;
    std::string	_attacks[5];
public:
            FragTrap(std::string newName);
            ~FragTrap();
            FragTrap(const FragTrap &tbc);
    void    operator = (const FragTrap &tbc);
    void	rangedAttack(std::string const & target);
    void	meleeAttack(std::string const & target);
    void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
    void    vaulthunter_dot_exe(std::string const & target);
};

#endif
