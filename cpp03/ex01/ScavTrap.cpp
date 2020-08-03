#include "ScavTrap.hpp"
#include <string>
#include <iostream>
#include <fstream>

ScavTrap::ScavTrap(std::string newName): name(newName)
{
    hitPoints = 100;
    maxHitPoints = 100;
    energyPoints = 50;
    maxEnergyPoints = 50;
    level = 1;
    meleeAttackDamage = 20;
    rangedAttackDamage = 15;
    armorDamageReduction = 3;
    output.open("ScavTrap.output", std::ios::trunc);
    attacks[0] = "Lightning bolt\n\n";
	attacks[1] = "Scratch\n\n";
	attacks[2] = "Growl\n\n";
	attacks[3] = "Hyper beam\n\n";
	attacks[4] = "Splash\n\n";
    enemies[0] = "Mr. Mime";
    enemies[1] = "Meowth";
    enemies[2] = "Team rocket";
}

ScavTrap::~ScavTrap(){}

void	ScavTrap::rangedAttack(std::string const & target)
{
	if (hitPoints == 0)
		output << "FR4G-TP " << name << " is dead can't use ranged attack!\n\n";
    else
    	output << "FR4G-TP " << name << " attacks " << target << " at range, causing " << rangedAttackDamage << " points of damage!\n\n";
}

void	ScavTrap::meleeAttack(std::string const & target)
{
	if (hitPoints == 0)
		output << "FR4G-TP " << name << " is dead can't use melee attack!\n\n";
    else
    	output << "FR4G-TP " << name << " attacks " << target << " with a knife, causing " << meleeAttackDamage << " points of damage!\n\n";
}

void	ScavTrap::takeDamage(unsigned int amount)
{
    if (hitPoints == 0)
        output << "FR4G-TP " << name << " is already dead, can't take more damage!\n\n";
    else if (hitPoints - amount + armorDamageReduction <= 0) {
        hitPoints = 0;
        output << "FR4G-TP " << name << " died!\n\n";
    } else {
    	hitPoints -= amount + armorDamageReduction;
		if (hitPoints < 0)
			hitPoints = 0;
        output << "FR4G-TP " << name << " got attacked, and took " << amount + armorDamageReduction << " points of damage!\n\n";
	}
}

void	ScavTrap::beRepaired(unsigned int amount)
{
    if (hitPoints == 0)
        output << "FR4G-TP " << name << " is dead, can't heal!\n\n";
    else if (hitPoints == maxHitPoints)
        output << "FR4G-TP " << name << " is already full health!\n\n";
    else {
        hitPoints += amount;
        if (hitPoints > maxHitPoints)
            hitPoints = maxHitPoints;
        output << "FR4G-TP " << name << " healed, current health is " << hitPoints << std::endl << std::endl;
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
            output << "FR4G-TP " << name << " attacks " << enemies[enemy] << " with " << attacks[attack]; 
        } else {
            int regenAmount = rand() % 100;
            beRepaired(regenAmount);
        }
        output << "FR4G-TP " << enemies[enemy] << " attacks\n\n";
        takeDamage(20);
    }
}
