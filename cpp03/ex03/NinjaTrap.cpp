#include "NinjaTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <string>
#include <iostream>

NinjaTrap::NinjaTrap(std::string newName): ClapTrap(newName)
{
    _type = "NINJ4-TP";
    _hitPoints = 60;
    _maxHitPoints = 60;
    _energyPoints = 120;
    _maxEnergyPoints = 120;
    _level = 1;
    _meleeAttackDamage = 60;
    _rangedAttackDamage = 5;
    _armorDamageReduction = 0;
    std::cout << "NinjaTrap constructor\n";
}

NinjaTrap::~NinjaTrap(){
    std::cout << "NinjaTrap destructor\n";
}

NinjaTrap::NinjaTrap(const NinjaTrap &tbc)
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

void    NinjaTrap::operator = (const NinjaTrap &tbc)
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

void    NinjaTrap::ninjaShoebox(const NinjaTrap& ninja)
{
	std::cout << _type << " " << _name << " attacked " << ninja._name << " with his katana!\n\n";
}

void    NinjaTrap::ninjaShoebox(const ScavTrap& scav)
{
	std::cout << _type << " " << _name << " attacked " << scav.getName() << " with his shuriken!\n\n";
}

void    NinjaTrap::ninjaShoebox(const FragTrap& frag)
{
	std::cout << _type << " " << _name << " attacked " << frag.getName() << " with his small toe!\n\n";
}
