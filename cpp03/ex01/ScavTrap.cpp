#include "ScavTrap.hpp"
#include <string>
#include <iostream>
#include <fstream>

ScavTrap::ScavTrap(std::string newName): _name(newName)
{
    _hitPoints = 100;
    _maxHitPoints = 100;
    _energyPoints = 50;
    _maxEnergyPoints = 50;
    _level = 1;
    _meleeAttackDamage = 20;
    _rangedAttackDamage = 15;
    _armorDamageReduction = 3;
    _attacks[0] = "Lightning bolt";
	_attacks[1] = "Scratch";
	_attacks[2] = "Growl";
	_attacks[3] = "Hyper beam";
	_attacks[4] = "Splash";
    _enemies[0] = "Mr. Mime";
    _enemies[1] = "Meowth";
    _enemies[2] = "Team rocket";
}

ScavTrap::~ScavTrap(){}

ScavTrap::ScavTrap(const ScavTrap &tbc)
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
    this->_enemies[0] = tbc._enemies[0];
    this->_enemies[1] = tbc._enemies[1];
    this->_enemies[2] = tbc._enemies[2];
}

void    ScavTrap::operator = (const ScavTrap &tbc)
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
    this->_enemies[0] = tbc._enemies[0];
    this->_enemies[1] = tbc._enemies[1];
    this->_enemies[2] = tbc._enemies[2];
}

void	ScavTrap::rangedAttack(std::string const & target)
{
	if (_hitPoints == 0)
		std::cout << "SC4V-TP " << _name << " is dead can't use ranged attack!\n\n";
    else
    	std::cout << "SC4V-TP " << _name << " attacks " << target << " at range, causing " << _rangedAttackDamage << " points of damage!\n\n";
}

void	ScavTrap::meleeAttack(std::string const & target)
{
	if (_hitPoints == 0)
		std::cout << "SC4V-TP " << _name << " is dead can't use melee attack!\n\n";
    else
    	std::cout << "SC4V-TP " << _name << " attacks " << target << " with a knife, causing " << _meleeAttackDamage << " points of damage!\n\n";
}

void	ScavTrap::takeDamage(unsigned int amount)
{
    if (_hitPoints == 0)
        std::cout << "SC4V-TP " << _name << " is already dead, can't take more damage!\n\n";
    else if (_hitPoints - amount + _armorDamageReduction <= 0) {
        _hitPoints = 0;
        std::cout << "SC4V-TP " << _name << " died!\n\n";
    } else {
    	_hitPoints -= amount + _armorDamageReduction;
		if (_hitPoints < 0)
			_hitPoints = 0;
        std::cout << "SC4V-TP " << _name << " got attacked, and took " << amount + _armorDamageReduction << " points of damage!\n\n";
	}
}

void	ScavTrap::beRepaired(unsigned int amount)
{
    if (_hitPoints == 0)
        std::cout << "SC4V-TP " << _name << " is dead, can't heal!\n\n";
    else if (_hitPoints == _maxHitPoints)
        std::cout << "SC4V-TP " << _name << " is already full health!\n\n";
    else {
        _hitPoints += amount;
        if (_hitPoints > _maxHitPoints)
            _hitPoints = _maxHitPoints;
        std::cout << "SC4V-TP " << _name << " healed, current health is " << _hitPoints << std::endl << std::endl;
    }
}

void    ScavTrap::challengeNewcomer()
{
    srand(time(NULL));
    int moves = rand() % 10;
    int enemy = moves % 3;

    for (int i = 0; i < moves + 1; i++) {
        bool shouldAttack = rand() % 2;
        if (shouldAttack == 1) {
            int attack = rand() % 5;
            std::cout << "SC4V-TP " << _name << " attacks " << _enemies[enemy] << " with " << _attacks[attack]; 
        } else {
            int regenAmount = rand() % 100;
            beRepaired(regenAmount);
        }
        std::cout << "SC4V-TP " << _enemies[enemy] << " attacks\n\n";
        takeDamage(20);
    }
}
