
#include "Victim.hpp"
#include "Sorcerer.hpp"
#include "Peon.hpp"
#include <iostream>
#include <string>

int main()
{
	// Person Person("bigb", "is altijd te laat");
	// Sorcerer Sorcerer("tim", "thetatman");
	// Sorcerer.Introduce();
	// sorcerer tim("tim", "the tatman");

	Sorcerer robert("Robert", "the Magnificent");
	Victim jim("Jimmy");
	Peon joe("Joe");
	std::cout << robert << jim << joe;
	robert.polymorph(jim);
	robert.polymorph(joe);
	return 0;
}