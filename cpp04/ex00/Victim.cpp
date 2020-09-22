
#include "Victim.hpp"
#include <iostream>
#include <string>

Victim::Victim(std::string n) : _name(n)
{
	std::cout << "Some random victim called " << _name << " just appeared!" << std::endl;
}

Victim::~Victim()
{
	std::cout << "Victim " << _name << " just died for no apparent reason!" << std::endl;
}

Victim::Victim(const Victim &copy) : _name(copy._name){}

void 		Victim::operator = (const Victim &s )
{
	if (&s != this)
		this->_name = s._name;
}


void		Victim::getPolymorphed() const
{
	std::cout << _name << " has been turned into a cute little sheep!" << std::endl;
}

std::string	Victim::getName() const
{
	return _name;
}

std::ostream   &operator << (std::ostream &out, const Victim &tbp)
{
    out << "I'm " << tbp.getName() << " and I like otters!" << std::endl;
    return out;
}