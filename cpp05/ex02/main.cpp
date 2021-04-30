
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <exception>
#include <iostream>

int main(void)
{
	std::cout << "----------------------------------------------------" << std::endl;
	try {
		Bureaucrat *dude = new Bureaucrat("dude", 42);
		ShrubberyCreationForm *corona = new ShrubberyCreationForm("corona");
		dude->signForm(*corona);
		dude->executeForm(*corona);
		std::cout << *corona << *dude;
	}
	catch (const std::exception  &msg) {
		std::cout << msg.what() << std::endl;
	}

	std::cout << "----------------------------------------------------" << std::endl;
	try {
		Bureaucrat *dude = new Bureaucrat("dude", 42);
		RobotomyRequestForm *robot = new RobotomyRequestForm("robot");
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
		PresidentialPardonForm *president = new PresidentialPardonForm("president");
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
		ShrubberyCreationForm *corona = new ShrubberyCreationForm("corona");
		newbie->signForm(*corona);
		newbie->executeForm(*corona);
		std::cout << *corona << *newbie;
	}
	catch (const std::exception  &msg) {
		std::cout << msg.what() << std::endl;
	}

	std::cout << "----------------------------------------------------" << std::endl;
	try {
		Bureaucrat *newbie = new Bureaucrat("newbie", 70);
		RobotomyRequestForm *robot = new RobotomyRequestForm("robot");
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
		PresidentialPardonForm *president = new PresidentialPardonForm("president");
		newbie->signForm(*president);
		newbie->executeForm(*president);
		std::cout << *president << *newbie;
	}
	catch (const std::exception  &msg) {
		std::cout << msg.what() << std::endl;
	}

	std::cout << std::endl << std::endl;
	system("leaks a.out | grep 'leaks for'");
	return 0;
}