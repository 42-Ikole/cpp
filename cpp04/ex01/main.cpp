
#include "Character.hpp"
#include "AWeapon.hpp"
#include "PlasmaRifle.hpp"
#include "RadScorpion.hpp"
#include "SuperMutant.hpp"
#include "PowerFist.hpp"
#include "Minigun.hpp"
#include "Arnold.hpp"
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

	Enemy *mvp = new Arnold();
	AWeapon *brrrr = new Minigun();
	me->equip(brrrr);
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 4; j++) {
			me->recoverAP();
		}
		me->attack(mvp);
		std::cout << "Arnold is now: " << mvp->getHP() << "HP" << std::endl;
	}
	system("leaks a.out | grep 'leaks for'");
	return 0;
}