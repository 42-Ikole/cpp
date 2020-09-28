
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
	}
	catch (const std::exception  &msg) {
		std::cout << msg.what() << std::endl;
	}

	return 0;
}