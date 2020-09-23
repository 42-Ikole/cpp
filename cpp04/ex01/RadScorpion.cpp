
#include "RadScorpion.hpp"
#include "Enemy.hpp"
#include <iostream>

RadScorpion::RadScorpion() : Enemy(80, "RadScorpion")
{
	std::cout << "* click click click *" << std::endl;
}

RadScorpion::~RadScorpion()
{
	std::cout << "* SPROTCH *" << std::endl;
}

RadScorpion::RadScorpion(const RadScorpion &copy) : Enemy(copy.getHP(), copy.getType()) {}

void 		RadScorpion::operator = (const RadScorpion &s )
{
	if (this != &s)
	{
		setHP(s.getHP());
		setType(s.getType());
	}
}
