
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <exception>
#include <iostream>

int main(void)
{
	try {
		Bureaucrat *dude = new Bureaucrat("dude", 42);
		Bureaucrat *newbie = new Bureaucrat("newbie", 140);
		Form *one = new Form("01", 50, 59);
		Form *two = new Form("02", 50, 60);
		dude->signForm(*one);
		newbie->signForm(*one);
		std::cout << *dude;
		std::cout << *one;
		std::cout << *newbie;
		std::cout << *two;
		delete dude;
		delete newbie;
		delete one;
		delete two;
	}
	catch (const std::exception  &msg) {
		std::cout << msg.what() << std::endl;
	}
	try {
		Bureaucrat *Low = new Bureaucrat("Low", 170);
		std::cout << Low;
	} catch (const std::exception  &msg) {
		std::cout << msg.what() << std::endl;
	}
	try {
		Bureaucrat *High = new Bureaucrat("High", 0);
		std::cout << High;
	} catch (const std::exception  &msg) {
		std::cout << msg.what() << std::endl;
	}
	std::cout << std::endl << std::endl;
	system("leaks a.out | grep 'leaks for'");
	return 0;
}