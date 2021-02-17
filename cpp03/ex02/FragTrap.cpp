
#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include <string>
#include <iostream>

FragTrap::FragTrap(std::string newName): ClapTrap(newName)
{
	std::cout << "FragTrap constructor!\n";
	_type = "FR4G-TP";
    _hitPoints = 100;
    _maxHitPoints = 100;
    _energyPoints = 100;
    _maxEnergyPoints = 100;
    _level = 1;
    _meleeAttackDamage = 30;
    _rangedAttackDamage = 20;
    _armorDamageReduction = 5;
	_attacks[0] = "Lightning bolt";
	_attacks[1] = "Scratch";
	_attacks[2] = "Growl";
	_attacks[3] = "Hyper beam";
	_attacks[4] = "Splash";
}

FragTrap::~FragTrap(){
	std::cout << "FragTrap destruction!\n";
}

void	FragTrap::vaulthunter_dot_exe(std::string const & target)
{
	if (_hitPoints == 0)
		std::cout << _type << " " << _name << " is dead, can't use random attack!\n\n";
    else if (_energyPoints < 25)
		std::cout << _type << " " << _name << " has insufficient energy!\n\n";
	else {
		_energyPoints -= 25;
		int attack = rand() % 5;
		std::cout << _type << " " << _name << " used " << _attacks[attack] << " on " << target << std::endl;
	}
}