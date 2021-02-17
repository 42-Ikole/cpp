#include "ScavTrap.hpp"
#include <string>
#include <iostream>

ScavTrap::ScavTrap(std::string newName): ClapTrap(newName)
{
    _hitPoints = 100;
    _maxHitPoints = 100;
    _energyPoints = 50;
    _maxEnergyPoints = 50;
    _level = 1;
    _meleeAttackDamage = 20;
    _rangedAttackDamage = 15;
    _armorDamageReduction = 3;
    _attacks[0] = "Lightning bolt\n\n";
	_attacks[1] = "Scratch\n\n";
	_attacks[2] = "Growl\n\n";
	_attacks[3] = "Hyper beam\n\n";
	_attacks[4] = "Splash\n\n";
    _enemies[0] = "Mr. Mime";
    _enemies[1] = "Meowth";
    _enemies[2] = "Team rocket";
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
            std::cout << "FR4G-TP " << _name << " attacks " << _enemies[enemy] << " with " << _attacks[attack]; 
        } else {
            int regenAmount = rand() % 100;
            beRepaired(regenAmount);
        }
        std::cout << "FR4G-TP " << _enemies[enemy] << " attacks\n\n";
        takeDamage(20);
    }
}
