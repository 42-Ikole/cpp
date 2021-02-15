
#include "FragTrap.hpp"
#include <string>
#include <iostream>

FragTrap::FragTrap(std::string newName): _name(newName)
{
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

FragTrap::~FragTrap(){}

void	FragTrap::rangedAttack(std::string const & target)
{
	if (_hitPoints == 0)
		std::cout << "FR4G-TP " << _name << " is dead can't use ranged attack!\n\n";
    else
    	std::cout << "FR4G-TP " << _name << " attacks " << target << " at range, causing " << _rangedAttackDamage << " points of damage!\n\n";
}

void	FragTrap::meleeAttack(std::string const & target)
{
	if (_hitPoints == 0)
		std::cout << "FR4G-TP " << _name << " is dead can't use melee attack!\n\n";
    else
    	std::cout << "FR4G-TP " << _name << " attacks " << target << " with a knife, causing " << _meleeAttackDamage << " points of damage!\n\n";
}

void	FragTrap::takeDamage(unsigned int amount)
{
    if (_hitPoints == 0)
        std::cout << "FR4G-TP " << _name << " is already dead, can't take more damage!\n\n";
    else if (_hitPoints - amount + _armorDamageReduction <= 0) {
        _hitPoints = 0;
        std::cout << "FR4G-TP " << _name << " died!\n\n";
    } else {
    	_hitPoints -= amount + _armorDamageReduction;
		if (_hitPoints < 0)
			_hitPoints = 0;
        std::cout << "FR4G-TP " << _name << " got attacked, and took " << amount + _armorDamageReduction << " points of damage!\n\n";
	}
}

void	FragTrap::beRepaired(unsigned int amount)
{
    if (_hitPoints == 0)
        std::cout << "FR4G-TP " << _name << " is dead, can't heal!\n\n";
    else if (_hitPoints == _maxHitPoints)
        std::cout << "FR4G-TP " << _name << " is already full health!\n\n";
    else {
        _hitPoints += amount;
        if (_hitPoints > _maxHitPoints)
            _hitPoints = _maxHitPoints;
        std::cout << "FR4G-TP " << _name << " healed, current health is " << _hitPoints << std::endl << std::endl;
    }
}

void	FragTrap::vaulthunter_dot_exe(std::string const & target)
{
	if (_hitPoints == 0)
		std::cout << "FR4G-TP " << _name << " is dead, can't use random attack!\n\n";
    else if (_energyPoints < 25)
		std::cout << "FR4G-TP " << _name << " has insufficient energy!\n\n";
	else {
		_energyPoints -= 25;
		srand(time(NULL));
		int attack = rand() % 5;
		std::cout << "FR4G-TP " << _name << " used " << _attacks[attack] <<  " on " << target << std::endl << std::endl;
	}
}
