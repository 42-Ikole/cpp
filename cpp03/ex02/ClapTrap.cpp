
#include "ClapTrap.hpp"
#include <string>
#include <iostream>

ClapTrap::ClapTrap(){
	std::cout << "Claptrap constructor!\n";
}

ClapTrap::ClapTrap(std::string &newName) :
    _name(newName)
{
    std::cout << "Claptrap constructor!" << std::endl;
}

ClapTrap::~ClapTrap(){
	std::cout << "Claptrap destruction!\n";
}

void	ClapTrap::rangedAttack(std::string const & target)
{
	if (_hitPoints == 0)
		std::cout << "FR4G-TP " << _name << " is dead can't use ranged attack!\n\n";
    else
    	std::cout << "FR4G-TP " << _name << " attacks " << target << " at range, causing " << _rangedAttackDamage << " points of damage!\n\n";
}

void	ClapTrap::meleeAttack(std::string const & target)
{
	if (_hitPoints == 0)
		std::cout << "FR4G-TP " << _name << " is dead can't use melee attack!\n\n";
    else
    	std::cout << "FR4G-TP " << _name << " attacks " << target << " with a knife, causing " << _meleeAttackDamage << " points of damage!\n\n";
}

void	ClapTrap::takeDamage(unsigned int amount)
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

void	ClapTrap::beRepaired(unsigned int amount)
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
