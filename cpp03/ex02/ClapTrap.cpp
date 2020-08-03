
#include "ClapTrap.hpp"
#include <string>
#include <iostream>

ClapTrap::ClapTrap(){
	std::cout << "Claptrap constructor!\n";
}

ClapTrap::~ClapTrap(){
	std::cout << "Claptrap destruction!\n";
}

void	ClapTrap::rangedAttack(std::string const & target)
{
	if (hitPoints == 0)
		std::cout << "FR4G-TP " << name << " is dead can't use ranged attack!\n\n";
    else
    	std::cout << "FR4G-TP " << name << " attacks " << target << " at range, causing " << rangedAttackDamage << " points of damage!\n\n";
}

void	ClapTrap::meleeAttack(std::string const & target)
{
	if (hitPoints == 0)
		std::cout << "FR4G-TP " << name << " is dead can't use melee attack!\n\n";
    else
    	std::cout << "FR4G-TP " << name << " attacks " << target << " with a knife, causing " << meleeAttackDamage << " points of damage!\n\n";
}

void	ClapTrap::takeDamage(unsigned int amount)
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

void	ClapTrap::beRepaired(unsigned int amount)
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
