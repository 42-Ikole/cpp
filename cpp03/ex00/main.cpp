
#include "FragTrap.hpp"


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
}