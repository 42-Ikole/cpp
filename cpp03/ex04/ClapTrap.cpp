
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

ClapTrap::ClapTrap(const ClapTrap &tbc)
{
    this->_name = tbc._name;
    this->_hitPoints = tbc._hitPoints;
    this->_maxHitPoints = tbc._maxHitPoints;
    this->_energyPoints = tbc._energyPoints;
    this->_maxEnergyPoints = tbc._maxEnergyPoints;
    this->_level = tbc._level;
    this->_meleeAttackDamage = tbc._meleeAttackDamage;
    this->_rangedAttackDamage = tbc._rangedAttackDamage;
    this->_armorDamageReduction = tbc._armorDamageReduction;
    this->_attacks[0] = tbc._attacks[0];
    this->_attacks[1] = tbc._attacks[1];
    this->_attacks[2] = tbc._attacks[2];
    this->_attacks[3] = tbc._attacks[3];
    this->_attacks[4] = tbc._attacks[4];
}

void    ClapTrap::operator = (const ClapTrap &tbc)
{
    this->_name = tbc._name;
    this->_hitPoints = tbc._hitPoints;
    this->_maxHitPoints = tbc._maxHitPoints;
    this->_energyPoints = tbc._energyPoints;
    this->_maxEnergyPoints = tbc._maxEnergyPoints;
    this->_level = tbc._level;
    this->_meleeAttackDamage = tbc._meleeAttackDamage;
    this->_rangedAttackDamage = tbc._rangedAttackDamage;
    this->_armorDamageReduction = tbc._armorDamageReduction;
    this->_attacks[0] = tbc._attacks[0];
    this->_attacks[1] = tbc._attacks[1];
    this->_attacks[2] = tbc._attacks[2];
    this->_attacks[3] = tbc._attacks[3];
    this->_attacks[4] = tbc._attacks[4];
}

void	ClapTrap::rangedAttack(std::string const & target)
{
	if (_hitPoints == 0)
		std::cout << _type << " " << _name << " is dead can't use ranged attack!\n\n";
    else
    	std::cout << _type << " " << _name << " attacks " << target << " at range, causing " << _rangedAttackDamage << " points of damage!\n\n";
}

void	ClapTrap::meleeAttack(std::string const & target)
{
	if (_hitPoints == 0)
		std::cout << _type << " " << _name << " is dead can't use melee attack!\n\n";
    else
    	std::cout << _type << " " << _name << " attacks " << target << " with a knife, causing " << _meleeAttackDamage << " points of damage!\n\n";
}

void	ClapTrap::takeDamage(unsigned int amount)
{
    if (_hitPoints == 0)
        std::cout << _type << " " << _name << " is already dead, can't take more damage!\n\n";
    else if (_hitPoints - amount + _armorDamageReduction <= 0) {
        _hitPoints = 0;
        std::cout << _type << " " << _name << " died!\n\n";
    } else {
    	_hitPoints -= amount + _armorDamageReduction;
		if (_hitPoints < 0)
			_hitPoints = 0;
        std::cout << _type << " " << _name << " got attacked, and took " << amount + _armorDamageReduction << " points of damage!\n\n";
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
    if (_hitPoints == 0)
        std::cout << _type << " " << _name << " is dead, can't heal!\n\n";
    else if (_hitPoints == _maxHitPoints)
        std::cout << _type << " " << _name << " is already full health!\n\n";
    else {
        _hitPoints += amount;
        if (_hitPoints > _maxHitPoints)
            _hitPoints = _maxHitPoints;
        std::cout << _type << " " << _name << " healed, current health is " << _hitPoints << std::endl << std::endl;
    }
}
