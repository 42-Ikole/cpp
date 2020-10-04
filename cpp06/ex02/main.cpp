
#include "Base.hpp"
#include "ABC.hpp"
#include <stdlib.h>
#include <time.h>
#include <iostream>

Base * generate(void)
{
	int i = rand() % 3;
	if (i == 0)
	{
		std::cout << "Chosen type = A" << std::endl;
		return new A;
	}
	else if (i == 1)
	{
		std::cout << "Chosen type = B" << std::endl;
		return new B;
	}
	else
	{
		std::cout << "Chosen type = B" << std::endl;
		return new C;
	}
}

void identify_from_pointer(Base * p)
{
	std::cout << std::endl << "Identified from pointer = ";
	Base *test;
	test = dynamic_cast<A*>(p);
	if (test != NULL)
		std::cout << "A" << std::endl;
	test = dynamic_cast<B*>(p);
	if (test != NULL)
		std::cout << "B" << std::endl;
	test = dynamic_cast<C*>(p);
	if (test != NULL)
		std::cout << "C" << std::endl;
}

void identify_from_reference( Base & p)
{
	std::cout << std::endl << "Identified from reference = ";
	Base *test;
	test = dynamic_cast<A*>(&p);
	if (test != NULL)
		std::cout << "A" << std::endl;
	test = dynamic_cast<B*>(&p);
	if (test != NULL)
		std::cout << "B" << std::endl;
	test = dynamic_cast<C*>(&p);
	if (test != NULL)
		std::cout << "C" << std::endl;
}

int main(void)
{
	srand(time(NULL));

	Base *unknown = generate();

	identify_from_pointer(unknown);
	identify_from_reference(*unknown);

	return 0;
}