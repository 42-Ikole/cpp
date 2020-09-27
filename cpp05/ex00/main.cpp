
#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>

int main(void)
{
	try
	{
		Bureaucrat *dude = new Bureaucrat("dude", 200);
	}
	catch (const char * msg)
	{
		std::cout << msg << std::endl;
	}
	return 0;
}