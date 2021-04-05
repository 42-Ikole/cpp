
#include "SuperMutant.hpp"
#include "Enemy.hpp"
#include <iostream>

SuperMutant::SuperMutant() : Enemy(170, "SuperMutant") 
{
	std::cout << "Gaaah. Me want smash heads!" << std::endl;
}

SuperMutant::~SuperMutant()
{
	std::cout << "Aaargh..." << std::endl;
}

SuperMutant::SuperMutant(const SuperMutant &copy) : Enemy(copy.getHP(), copy.getType()) {}

SuperMutant	&SuperMutant::operator = (const SuperMutant &s )
{
	if (this != &s)
	{
		setHP(s.getHP());
		setType(s.getType());
	}
	return *this;
}

void SuperMutant::takeDamage(int damage)
{
	if (damage > 3)
		damage -= 3;
	else
		damage = 0;
	if (getHP() - damage <= 0)
		setHP(0);
	else
		setHP(getHP() - damage);
	if (getHP() == 0)
		delete this;
}
