
#include "Arnold.hpp"
#include "Enemy.hpp"
#include <iostream>

Arnold::Arnold() : Enemy(420, "Arnold") 
{
	std::cout << "HWUAA GET TO ZE CHOPPA!" << std::endl;
}

Arnold::~Arnold()
{
	std::cout << "HWUAA" << std::endl;
}

Arnold::Arnold(const Arnold &copy) : Enemy(copy.getHP(), copy.getType()) {}

Arnold	&Arnold::operator = (const Arnold &s )
{
	if (this != &s)
	{
		setHP(s.getHP());
		setType(s.getType());
	}
	return *this;
}

void Arnold::takeDamage(int damage)
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
