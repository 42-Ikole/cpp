#include "ScavTrap.hpp"
#include <string>
#include <iostream>

ScavTrap::ScavTrap(std::string newName): pname(newName)
{
    pname = newName;
    hitPoints = 100;
    maxHitPoints = 100;
    energyPoints = 50;
    maxEnergyPoints = 50;
    level = 1;
    meleeAttackDamage = 20;
    rangedAttackDamage = 15;
    armorDamageReduction = 3;
    attacks[0] = "Lightning bolt\n\n";
	attacks[1] = "Scratch\n\n";
	attacks[2] = "Growl\n\n";
	attacks[3] = "Hyper beam\n\n";
	attacks[4] = "Splash\n\n";
    enemies[0] = "Mr. Mime";
    enemies[1] = "Meowth";
    enemies[2] = "Team rocket";
    std::cout << "ScavTrap constructor\n";
}

ScavTrap::~ScavTrap(){
    std::cout << "ScavTrap destructor\n";
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
            std::cout << "FR4G-TP " << name << " attacks " << enemies[enemy] << " with " << attacks[attack]; 
        } else {
            int regenAmount = rand() % 100;
            beRepaired(regenAmount);
        }
        std::cout << "FR4G-TP " << enemies[enemy] << " attacks\n\n";
        takeDamage(20);
    }
}
