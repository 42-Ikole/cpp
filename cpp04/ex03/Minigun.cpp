
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "Minigun.hpp"
#include <iostream>

Minigun::Minigun() : AMateria("Minigun") {}

Minigun::~Minigun() {}

Minigun::Minigun(const Minigun &Minigun) : AMateria("Minigun")
{
	setXP(Minigun.getXP());
}

Minigun	&Minigun::operator = (const Minigun &s)
{
	if (&s != this)
	{
		this->setType(s.getType());
		this->setXP(s.getXP());
	}
	return *this;
}

AMateria*	Minigun::clone() const
{
	Minigun *clone = new (std::nothrow) Minigun(*this);
	if (!clone)
	{
		std::cout << "allocation for clone failed" << std::endl;
		return 	NULL;
	}	
	return clone;
}

void		Minigun::use(ICharacter& target)
{
	std::cout << "* BRRRRRRRRR *, " << target.getName() << " Looks like 'gatenkaas' after being shot with a minigun!" << std::endl;
	AMateria::use(target);
}
