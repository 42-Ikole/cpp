
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <exception>
#include <iostream>

int main(void)
{
	Intern randomIntern;
	
	std::cout << "----------------------------------------------------" << std::endl;
	try {
		Bureaucrat *dude = new Bureaucrat("dude", 42);
		AForm *shub = randomIntern.makeForm("shrubbery creation", "boris");
		dude->signForm(*shub);
		dude->executeForm(*shub);
		std::cout << *shub << *dude;
	}
	catch (const std::exception  &msg) {
		std::cout << msg.what() << std::endl;
	}

	std::cout << "----------------------------------------------------" << std::endl;
	try {
		Bureaucrat *dude = new Bureaucrat("dude", 42);
		AForm *robot = randomIntern.makeForm("robotomy request", "roboris");
		dude->signForm(*robot);
		dude->executeForm(*robot);
		std::cout << *robot << *dude;
	}
	catch (const std::exception  &msg) {
		std::cout << msg.what() << std::endl;
	}
	std::cout << "----------------------------------------------------" << std::endl;
	try {
		Bureaucrat *dude = new Bureaucrat("dude", 4);
		AForm *president = randomIntern.makeForm("presidential pardon", "boris");
		dude->signForm(*president);
		dude->executeForm(*president);
		std::cout << *president << *dude;
	}
	catch (const std::exception  &msg) {
		std::cout << msg.what() << std::endl;
	}

	std::cout << "\n\n\n----------------------------------------------------" << std::endl;
	try {
		Bureaucrat *newbie = new Bureaucrat("newbie", 140);
		AForm *shub = randomIntern.makeForm("shrubbery", "boris");
		newbie->signForm(*shub);
		newbie->executeForm(*shub);
		std::cout << *shub << *newbie;
	}
	catch (const std::exception  &msg) {
		std::cout << msg.what() << std::endl;
	}

	std::cout << "----------------------------------------------------" << std::endl;
	try {
		Bureaucrat *newbie = new Bureaucrat("newbie", 70);
		AForm *robot = randomIntern.makeForm("robotomy", "roboris");
		newbie->signForm(*robot);
		newbie->executeForm(*robot);
		std::cout << *robot << *newbie;
	}
	catch (const std::exception  &msg) {
		std::cout << msg.what() << std::endl;
	}
	std::cout << "----------------------------------------------------" << std::endl;
	try {
		Bureaucrat *newbie = new Bureaucrat("newbie", 20);
		AForm *president = randomIntern.makeForm("presidential", "boris");
		newbie->signForm(*president);
		newbie->executeForm(*president);
		std::cout << *president << *newbie;
	}
	catch (const std::exception  &msg) {
		std::cout << msg.what() << std::endl;
	}

	std::cout << std::endl << std::endl;
	system("leaks a.out");
	return 0;
}