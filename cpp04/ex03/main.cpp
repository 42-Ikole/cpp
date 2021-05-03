
#include "IMateriaSource.hpp"
#include "AMateria.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"
#include "ICharacter.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Minigun.hpp"
#include <iostream>

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");
	
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	
	ICharacter* bob = new Character("bob");
	
	me->use(0, *bob);
	me->use(1, *bob);
	me->unequip(1);
	me->use(1, *bob);
	me->equip(src->createMateria("ice"));
	me->use(1, *bob);


	src->learnMateria(new Minigun());
	AMateria* brrr = src->createMateria("Minigun");
	me->equip(brrr);
	me->use(2, *bob);
	
	src->createMateria("VERY COOL 42 SUBJECTS");
	
	delete bob;
	delete me;
	delete src;
	return 0;
}
