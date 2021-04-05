
#include "PlasmaRifle.hpp"
#include "AWeapon.hpp"
#include <string>
#include <iostream>

PlasmaRifle::PlasmaRifle() : AWeapon("PlasmaRifle", 5, 21) {}

PlasmaRifle::~PlasmaRifle() {}

PlasmaRifle::PlasmaRifle(const PlasmaRifle &copy) : AWeapon(copy.getName(), copy.getApCost(), copy.getDamage()) {}

PlasmaRifle	&PlasmaRifle::operator = (const PlasmaRifle &s )
{
	if (&s != this)
	{
		setName(s.getName());
		setDamage(s.getDamage());
		setApCost(s.getApCost());
	}
	return *this;
}

void	PlasmaRifle::attack() const
{
	std::cout << "* piouuu piouuu piouuu *" << std::endl;
}
