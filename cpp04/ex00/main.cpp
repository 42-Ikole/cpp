
#include "Victim.hpp"
#include "Sorcerer.hpp"
#include "Peon.hpp"
#include "Corona.hpp"
#include <iostream>
#include <string>

int main()
{
	Sorcerer bigb("bigb", "is altijd te laat");
	Peon tim("tim");
	Peon zazzle("zazzle");
	Peon irrelevant("Irrelevant");
	std::cout << bigb << tim;

	tim = zazzle = irrelevant;
	std::cout << tim <<  zazzle << irrelevant << std::endl;

	Sorcerer robert("Robert", "the Magnificent");
	Victim jim("Jimmy");
	Peon joe("Joe");
	std::cout << robert << jim << joe;
	robert.polymorph(jim);
	robert.polymorph(joe);

	Corona fuckrona("I hate lockdowns");
	bigb.polymorph(fuckrona);
	std::cout << fuckrona << std::endl;
	return 0;
}