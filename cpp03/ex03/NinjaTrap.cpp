#include "NinjaTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <string>
#include <iostream>

NinjaTrap::NinjaTrap(std::string newName): pname(newName)
{
    name = newName;
    hitPoints = 60;
    maxHitPoints = 60;
    energyPoints = 120;
    maxEnergyPoints = 120;
    level = 1;
    meleeAttackDamage = 60;
    rangedAttackDamage = 5;
    armorDamageReduction = 0;
    std::cout << "NinjaTrap constructor\n";
}

NinjaTrap::~NinjaTrap(){
    std::cout << "NinjaTrap destructor\n";
}

void    NinjaTrap::ninjaShoebox(const NinjaTrap& ninja)
{
	std::cout << "FR4G-TP " << name << " attacked " << ninja.name << " with his katana!\n\n";
}

void    NinjaTrap::ninjaShoebox(const ScavTrap& scav)
{
	std::cout << "FR4G-TP " << name << " attacked " << scav.name << " with his shuriken!\n\n";
}

void    NinjaTrap::ninjaShoebox(const FragTrap& frag)
{
	std::cout << "FR4G-TP " << name << " attacked " << frag.name << " with his small toe!\n\n";
}
