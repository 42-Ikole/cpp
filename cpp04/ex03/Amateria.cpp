
#include "AMateria.hpp"
#include <string>

AMateria::AMateria(std::string const & _type) : xp(0), type(_type) {}

AMateria::~AMateria() {}

AMateria::AMateria(const AMateria &amateria)
{
	this->xp = amateria.getXP();
	this->type = amateria.getType();
}

void	AMateria::operator = (const AMateria &amateria)
{
	if (&amateria != this)
	{
		this->xp = amateria.getXP();
		this->type = amateria.getType();
	}
}

std::string const & AMateria::getType() const
{
	return this->type;
}

void				AMateria::setType(std::string _type)
{
	this->type = _type;
}

unsigned int 		AMateria::getXP() const
{
	return this->xp;
}

void	AMateria::setXP(int xp)
{
	this->xp = xp;
}

void	AMateria::use(ICharacter& target)
{
	(void)target;
	this->xp += 10;
}
