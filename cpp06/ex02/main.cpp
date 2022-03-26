
#include "Base.hpp"
#include "ABC.hpp"
#include <stdlib.h>
#include <time.h>
#include <iostream>

Base * generate(void)
{
	int i = rand() % 3;
	std::cout << "Chosen type = ";
	switch (i)
	{
		case 0:
			std::cout << "A" << std::endl;
			return new A;
		case 1:
			std::cout << "B" << std::endl;
			return new B;
		default:
			std::cout << "C" << std::endl;
			return new C;
	}
}

void identify(Base* p)
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

template<typename T>
	void tryCast(Base& p)
{
	try {
		std::cout << dynamic_cast<T&>(p);
	} catch (const std::exception& e) {
		(void)e;
	}
}

void identify(Base& p)
{
	std::cout << std::endl << "Identified from reference = ";
	tryCast<A>(p);
	tryCast<B>(p);
	tryCast<C>(p);
}

int main(void)
{
	srand(time(NULL));

	Base *unknown = generate();

	identify(unknown);
	identify(*unknown);
	return 0;
}
