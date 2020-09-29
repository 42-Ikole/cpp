
#include "AForm.hpp"
#include "Intern.hpp"
#include <exception>
#include <iostream>

int main(void)
{
	Intern randomIntern;

	AForm *robot = randomIntern.makeForm("robotomy request", "boris");
	system("leaks a.out");
	return 0;
}