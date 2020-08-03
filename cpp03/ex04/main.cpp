
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"
#include "SuperTrap.hpp"

int main()
{
	FragTrap magikarp("Magikarp");

	magikarp.beRepaired(20);
	magikarp.meleeAttack("Ratata");
	magikarp.takeDamage(50);
	magikarp.rangedAttack("Ratata");
	magikarp.vaulthunter_dot_exe("Ratata");
	magikarp.takeDamage(20);
	magikarp.beRepaired(50);
	magikarp.vaulthunter_dot_exe("Ratata");
	magikarp.takeDamage(69);
	magikarp.vaulthunter_dot_exe("Ratata");
	magikarp.takeDamage(40);
	magikarp.vaulthunter_dot_exe("Ratata");
	magikarp.beRepaired(20);
	magikarp.takeDamage(10);

	ScavTrap eevee("Eevee");
	eevee.challengeNewcomer();
	eevee.beRepaired(100);
	eevee.challengeNewcomer();

	NinjaTrap ninja("ninja");
	ninja.ninjaShoebox(ninja);
	ninja.ninjaShoebox(eevee);
	ninja.ninjaShoebox(magikarp);

	SuperTrap super("Super");
	super.meleeAttack("melee enemy");
	super.rangedAttack("ranged enemy");
	super.takeDamage(10);
	super.beRepaired(15);
	super.ninjaShoebox(magikarp);
	super.vaulthunter_dot_exe("COVID-19");
}