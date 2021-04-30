#include "ISpaceMarine.hpp"
#include "TacticalMarine.hpp"
#include "AssaultTerminator.hpp"
#include "ISquad.hpp"
#include "Squad.hpp"
#include <iostream>

int		main(void)
{
	ISpaceMarine	*bob = new TacticalMarine();
	ISpaceMarine	*jim = new AssaultTerminator();

	ISquad			*vlc = new Squad();
	vlc->push(bob);
	vlc->push(jim);
	for (int i = 0; i < vlc->getCount(); ++i)
	{
		ISpaceMarine	*cur = vlc->getUnit(i);
		cur->battleCry();
		cur->rangedAttack();
		cur->meleeAttack();
	}
	delete vlc;

	// Other tests:

	std::cout << std::endl;
	std::cout << ">>> Trying to add a NULL pointer, and an already existing character." << std::endl;
	Squad			*squad1 = new Squad();
	int				push_return;

	push_return = squad1->push(NULL);
	std::cout << "Push return on NULL add: " << push_return << std::endl;
	bob = new TacticalMarine();
	squad1->push(bob);
	push_return = squad1->push(bob);
	std::cout << "Push return on double add: " << push_return << std::endl;
	delete squad1;

	std::cout << std::endl;

	std::cout << ">>> Creating a new squad with 5 units." << std::endl;
	squad1 = new Squad();
	for (int i = 0; i < 5; i++)
	{
		ISpaceMarine	*tmp;
		if (i % 2 == 0)
			tmp = new TacticalMarine();
		else
			tmp = new AssaultTerminator();
		std::cout << ">>> Push returns: " << squad1->push(tmp) << std::endl;
	}

	std::cout << std::endl;
	std::cout << ">>> Copying:" << std::endl;
	Squad			*squad2 = new Squad(*squad1);
	std::cout << ">>> Done copying, deleting the old squad." << std::endl;
	delete squad1;

	std::cout << ">>> Doing a battle cry from a unit of the copied squad." << std::endl;
	squad2->getUnit(2)->battleCry();
	std::cout << ">>> Deleting the copied squad." << std::endl;
	delete squad2;

	std::cout << std::endl;

	std::cout << ">>> Testing assignation with existing squad." << std::endl;
	squad1 = new Squad();
	squad1->push(new TacticalMarine());
	squad1->push(new AssaultTerminator());
	squad2 = new Squad();
	for (int i = 0; i < 5; i++)
	{
		squad2->push(new TacticalMarine());
	}
	std::cout << ">>> Assigning squad 1 to squad 2." << std::endl;
	*squad2 = *squad1;

	std::cout << std::endl;

	std::cout << ">>> Deleting both squads, copies with identical units." << std::endl;
	delete squad1;
	delete squad2;
	bob = 0;
	jim = 0;
	vlc = 0;
	squad1 = 0;
	squad2 = 0;
	
	std::cout << std::endl << std::endl;
	system("leaks a.out | grep 'leaks for'");
	return 0;
}
