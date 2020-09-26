
#include "AMateria.hpp"
#include <string>


AMateria::AMateria(std::string const & type) : _xp(0), _Type(type) {}

AMateria::~AMateria() {}

std::string const & AMateria::getType() const
{
	return _Type;
}

void				AMateria::setType(std::string type)
{
	_Type = type;
}

unsigned int 		AMateria::getXP() const
{
	return _xp;
}

void	AMateria::setXP(int xp)
{
	_xp = xp;
}

void AMateria::use(ICharacter& target)
{
	_xp += 10;
}
