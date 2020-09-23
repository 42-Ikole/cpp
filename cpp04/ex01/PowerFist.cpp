
#include "PowerFist.hpp"
#include "AWeapon.hpp"
#include <string>
#include <iostream>

PowerFist::PowerFist() : AWeapon("PowerFist", 8, 50) {}

PowerFist::~PowerFist() {}

PowerFist::PowerFist(const PowerFist &copy) : AWeapon(copy.getName(), copy.getApCost(), copy.getDamage()) {}

void 		PowerFist::operator = (const PowerFist &s )
{
	if (&s != this)
	{
		setName(s.getName());
		setDamage(s.getDamage());
		setApCost(s.getApCost());
	}
}

void	PowerFist::attack() const
{
	std::cout << "* pschhh... SBAM! *" << std::endl;
}
