
#include "Sorcerer.hpp"
#include "Victim.hpp"
#include <string>
#include <iostream>

Sorcerer::Sorcerer(std::string n, std::string t) : _name(n), _title(t)
{
	std::cout << _name << ", " << _title << ", is born!" << std::endl;
}

Sorcerer::~Sorcerer()
{
	std::cout << _name << ", " << _title << ", is dead. Consequences will never be the same!" << std::endl;
}

Sorcerer::Sorcerer(const Sorcerer &copy) : _name(copy._name), _title(copy._title){}

Sorcerer	&Sorcerer::operator = (const Sorcerer &s )
{
	if (&s != this)
	{
		this->_name = s._name;
		this->_title = s._title;
	}
	return *this;
}

std::string	Sorcerer::getName() const
{
	return _name;
}

std::string	Sorcerer::getTitle() const
{
	return _title;
}

std::ostream   &operator << (std::ostream &out, const Sorcerer &tbp)
{
    out << "I am " << tbp.getName() << ", " << tbp.getTitle() << ", and I like ponies!" << std::endl;
    return out;
}

void Sorcerer::polymorph(Victim const &target) const
{
	target.getPolymorphed();
}
