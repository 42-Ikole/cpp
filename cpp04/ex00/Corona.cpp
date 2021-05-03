#include "Victim.hpp"
#include "Sorcerer.hpp"
#include "Corona.hpp"
#include <iostream>
#include <string>

Corona::Corona(std::string n) : Victim(n)
{
	std::cout << "Muwahahahaha!!" << std::endl;
}

Corona::~Corona()
{
	std::cout << "AAAAHHHH not the vaccine!" << std::endl;
}

Corona::Corona(const Corona &copy) : Victim(copy)
{
	if (&copy != this)
		this->_name = copy.getName();
}

Corona 		&Corona::operator = (const Corona &s )
{
	if (&s != this)
		this->_name = s.getName();
	return *this;
}

void		Corona::getPolymorphed() const
{
	std::cout << getName() << " has been turned into a big problem!" << std::endl;
}
