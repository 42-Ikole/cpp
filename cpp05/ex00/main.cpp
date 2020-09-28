
#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>

int main(void)
{
	try {
		Bureaucrat *dude = new Bureaucrat("dude", 200);
		Bureaucrat *dude1 = new Bureaucrat("dude1", 0);
		std::cout << *dude << *dude1;
	}
	catch (const std::exception &msg) {
		std::cout << msg.what() << std::endl;
	}

	try {
		Bureaucrat *dude = new Bureaucrat("dude", 0);
		Bureaucrat *dude1 = new Bureaucrat("dude1", 200);
		std::cout << *dude << *dude1;
	}
	catch (const std::exception  &msg) {
		std::cout << msg.what() << std::endl;
	}

	try {
		Bureaucrat *dude = new Bureaucrat("dude", 42);
		std::cout << *dude;
	}
	catch (const std::exception  &msg) {
		std::cout << msg.what() << std::endl;
	}
	return 0;
}