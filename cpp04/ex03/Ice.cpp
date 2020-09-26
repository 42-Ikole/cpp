
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "Ice.hpp"
#include <iostream>

Ice::Ice() : AMateria("ice") {}

Ice::~Ice() {}

Ice::Ice(const Ice &Ice) : AMateria("ice") {}

void	Ice::operator = (const Ice &s)
{
	if (&s != this)
	{
		this->setType(s.getType());
		this->setXP(s.getXP());
	}
}

AMateria*	Ice::clone() const
{
	Ice *clone = new (std::nothrow) Ice(*this);

	if (!clone)
	{
		std::cout << "allocation for clone failed" << std::endl;
		return 	NULL;
	}
	return clone;
}

void		Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
