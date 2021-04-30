
#include "Character.hpp"
#include "AWeapon.hpp"
#include "PlasmaRifle.hpp"
#include "RadScorpion.hpp"
#include "SuperMutant.hpp"
#include "PowerFist.hpp"
#include <iostream>

int main()
{
	Character* me = new Character("me");
	std::cout << *me;
	Enemy* b = new RadScorpion();
	AWeapon* pr = new PlasmaRifle();
	AWeapon* pf = new PowerFist();
	me->equip(pr);
	std::cout << *me;
	me->equip(pf);
	me->attack(b);
	std::cout << *me;
	me->equip(pr);
	std::cout << *me;
	me->attack(b);
	std::cout << *me;
	me->attack(b);
	std::cout << *me;

	SuperMutant *SM = new SuperMutant();
	std::cout << SM->getType() << " (" << SM->getHP() << ") " << std::endl;
	me->attack(SM);
	std::cout << SM->getHP();
	SM->takeDamage(152);
	std::cout << std::endl << std::endl;


	system("leaks a.out | grep 'leaks for'");
	return 0;
}