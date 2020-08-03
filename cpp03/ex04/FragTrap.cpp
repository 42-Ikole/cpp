
#include "FragTrap.hpp"
#include <string>
#include <iostream>

FragTrap::FragTrap(){
	hitPoints = 100;
	maxHitPoints = 100;
	rangedAttackDamage = 30;
	armorDamageReduction = 5;
	attacks[0] = "Lightning bolt\n\n";
	attacks[1] = "Scratch\n\n";
	attacks[2] = "Growl\n\n";
	attacks[3] = "Hyper beam\n\n";
	attacks[4] = "Splash\n\n";
	std::cout << "FragTrap consturctor!\n";
}

FragTrap::FragTrap(std::string newName): pname(newName)
{
	std::cout << "FragTrap constructor!\n";
	name = newName;
    hitPoints = 100;
    maxHitPoints = 100;
    energyPoints = 100;
    maxEnergyPoints = 100;
    level = 1;
    meleeAttackDamage = 30;
    rangedAttackDamage = 20;
    armorDamageReduction = 5;
	attacks[0] = "Lightning bolt\n\n";
	attacks[1] = "Scratch\n\n";
	attacks[2] = "Growl\n\n";
	attacks[3] = "Hyper beam\n\n";
	attacks[4] = "Splash\n\n";
}

FragTrap::~FragTrap(){
	std::cout << "FragTrap destruction!\n";
}

void	FragTrap::vaulthunter_dot_exe(std::string const & target)
{
	if (hitPoints == 0)
		std::cout << "FR4G-TP " << name << " is dead, can't use random attack!\n\n";
    else if (energyPoints < 25)
		std::cout << "FR4G-TP " << name << " has insufficient energy!\n\n";
	else {
		energyPoints -= 25;
		int attack = rand() % 5;
		std::cout << "FR4G-TP " << name << " used " << attacks[attack];
	}
}