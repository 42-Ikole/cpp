
#include "Minigun.hpp"
#include "AWeapon.hpp"
#include <string>
#include <iostream>

Minigun::Minigun() : AWeapon("Minigun", 35, 69) {}

Minigun::~Minigun() {}

Minigun::Minigun(const Minigun &copy) : AWeapon(copy.getName(), copy.getApCost(), copy.getDamage()) {}

Minigun	&Minigun::operator = (const Minigun &s )
{
	if (&s != this)
	{
		setName(s.getName());
		setDamage(s.getDamage());
		setApCost(s.getApCost());
	}
	return *this;
}

void	Minigun::attack() const
{
	std::cout << "* MINIGUN GOES BRRRRRRRRRRRRR *" << std::endl;
}
