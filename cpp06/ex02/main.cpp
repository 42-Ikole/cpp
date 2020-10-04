
#include "ABase.hpp"
#include "ABC.hpp"
#include <stdlib.h>
#include <time.h>
#include <iostream>

ABase * generate(void)
{
	int i = rand() % 3;
	if (i == 0)
		return new A;
	else if (i == 1)
		return new B;
	else
		return new C;
}

void identify_from_pointer(ABase * p)
{
	ABase *test;
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

int main(void)
{
	srand(time(NULL));

	ABase *unknown = generate();

	identify_from_pointer(unknown);

	return 0;
}