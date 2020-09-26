
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "Cure.hpp"
#include <iostream>

Cure::Cure() : AMateria("cure") {}

Cure::~Cure() {}

Cure::Cure(const Cure &Cure) : AMateria("cure")
{
	setXP(Cure.getXP());
}

void	Cure::operator = (const Cure &s)
{
	if (&s != this)
	{
		this->setType(s.getType());
		this->setXP(s.getXP());
	}
}

AMateria*	Cure::clone() const
{
	Cure *clone = new (std::nothrow) Cure(*this);
	if (!clone)
	{
		std::cout << "allocation for clone failed" << std::endl;
		return 	NULL;
	}
	return clone;
}

void		Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}
