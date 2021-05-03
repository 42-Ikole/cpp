
#include "SuperTrap.hpp"
#include <string>
#include <iostream>

SuperTrap::SuperTrap(std::string newName): FragTrap(newName), NinjaTrap(newName)
{
    std::cout << "SuperTrap constructor\n";
    _type = "SUP3R-TP";
    _hitPoints = 100;
    _maxHitPoints = 100;
    _energyPoints = 120;
    _maxEnergyPoints = 120;
    _level = 1;
    _meleeAttackDamage = 60;
    _rangedAttackDamage = 20;
    _armorDamageReduction = 5;
    _attacks[0] = "Lightning bolt";
	_attacks[1] = "Scratch";
	_attacks[2] = "Growl";
	_attacks[3] = "Hyper beam";
	_attacks[4] = "Splash";
}

SuperTrap::~SuperTrap() {
    std::cout << "SuperTrap destructor\n";
}

SuperTrap::SuperTrap(const SuperTrap &tbc): FragTrap(tbc._name), NinjaTrap(tbc._name)
{
    this->_type = tbc._type;
    this->_hitPoints = tbc._hitPoints;
    this->_maxHitPoints = tbc._maxHitPoints;
    this->_energyPoints = tbc._energyPoints;
    this->_maxEnergyPoints = tbc._maxEnergyPoints;
    this->_level = tbc._level;
    this->_meleeAttackDamage = tbc._meleeAttackDamage;
    this->_rangedAttackDamage = tbc._rangedAttackDamage;
    this->_armorDamageReduction = tbc._armorDamageReduction;
    this->_attacks[0] = _attacks[0];
	this->_attacks[1] = _attacks[1];
	this->_attacks[2] = _attacks[2];
	this->_attacks[3] = _attacks[3];
	this->_attacks[4] = _attacks[4];
}
    
void    SuperTrap::operator = (const SuperTrap &tbc)
{
    this->_name = tbc._name;
    this->_type = tbc._type;
    this->_hitPoints = tbc._hitPoints;
    this->_maxHitPoints = tbc._maxHitPoints;
    this->_energyPoints = tbc._energyPoints;
    this->_maxEnergyPoints = tbc._maxEnergyPoints;
    this->_level = tbc._level;
    this->_meleeAttackDamage = tbc._meleeAttackDamage;
    this->_rangedAttackDamage = tbc._rangedAttackDamage;
    this->_armorDamageReduction = tbc._armorDamageReduction;
    this->_attacks[0] = _attacks[0];
	this->_attacks[1] = _attacks[1];
	this->_attacks[2] = _attacks[2];
	this->_attacks[3] = _attacks[3];
	this->_attacks[4] = _attacks[4];
}
