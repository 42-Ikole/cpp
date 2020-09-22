#include "FragTrap.hpp"

#include <string>
#include <iostream>

FragTrap::FragTrap(std::string newName): name(newName)
{
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

FragTrap::~FragTrap(){}

void	FragTrap::rangedAttack(std::string const & target)
{
	if (hitPoints == 0)
		std::cout << "FR4G-TP " << name << " is dead can't use ranged attack!\n\n";
    else
    	std::cout << "FR4G-TP " << name << " attacks " << target << " at range, causing " << rangedAttackDamage << " points of damage!\n\n";
}

void	FragTrap::meleeAttack(std::string const & target)
{
	if (hitPoints == 0)
		std::cout << "FR4G-TP " << name << " is dead can't use melee attack!\n\n";
    else
    	std::cout << "FR4G-TP " << name << " attacks " << target << " with a knife, causing " << meleeAttackDamage << " points of damage!\n\n";
}

void	FragTrap::takeDamage(unsigned int amount)
{
    if (hitPoints == 0)
        std::cout << "FR4G-TP " << name << " is already dead, can't take more damage!\n\n";
    else if (hitPoints - amount + armorDamageReduction <= 0) {
        hitPoints = 0;
        std::cout << "FR4G-TP " << name << " died!\n\n";
    } else {
    	hitPoints -= amount + armorDamageReduction;
		if (hitPoints < 0)
			hitPoints = 0;
        std::cout << "FR4G-TP " << name << " got attacked, and took " << amount + armorDamageReduction << " points of damage!\n\n";
	}
}

void	FragTrap::beRepaired(unsigned int amount)
{
    if (hitPoints == 0)
        std::cout << "FR4G-TP " << name << " is dead, can't heal!\n\n";
    else if (hitPoints == maxHitPoints)
        std::cout << "FR4G-TP " << name << " is already full health!\n\n";
    else {
        hitPoints += amount;
        if (hitPoints > maxHitPoints)
            hitPoints = maxHitPoints;
        std::cout << "FR4G-TP " << name << " healed, current health is " << hitPoints << std::endl << std::endl;
    }
}

void	FragTrap::vaulthunter_dot_exe(std::string const & target)
{
	if (hitPoints == 0)
		std::cout << "FR4G-TP " << name << " is dead, can't use random attack!\n\n";
    else if (energyPoints < 25)
		std::cout << "FR4G-TP " << name << " has insufficient energy!\n\n";
	else {
		energyPoints -= 25;
		srand(time(NULL));
		int attack = rand() % 5;
		std::cout << "FR4G-TP " << name << " used " << attacks[attack];
	}
}
