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

Peon::Peon(const Peon &copy) : Victim(copy){}

void 		Peon::operator = (const Peon &s )
{
	if (&s != this)
		this->_name = s.getName();
}

void		Peon::getPolymorphed() const
{
	std::cout << getName() << " has been turned into a pink pony!" << std::endl;
}
