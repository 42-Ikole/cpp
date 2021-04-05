#include "Victim.hpp"
#include "Sorcerer.hpp"
#include "Peon.hpp"
#include <iostream>
#include <string>

Peon::Peon(std::string n) : Victim(n)
{
	std::cout << "Zog zog." << std::endl;
}

Peon::~Peon()
{
	std::cout << "Bleuark..." << std::endl;
}

Peon::Peon(const Peon &copy) : Victim(copy)
{
	if (&copy != this)
		this->_name = copy.getName();
}

Peon 		&Peon::operator = (const Peon &s )
{
	if (&s != this)
		this->_name = s.getName();
	return *this;
}

void		Peon::getPolymorphed() const
{
	std::cout << getName() << " has been turned into a pink pony!" << std::endl;
}
