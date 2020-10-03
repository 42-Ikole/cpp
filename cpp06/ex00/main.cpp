
#include "PrintInput.hpp"
#include <iostream>

int		main(int count, char **thiccJonas)
{
	if (count != 2)
	{
		std::cerr << "wrong number of arguments amigo!" << std::endl;
		return 0;
	}
	PrintInput pnb = PrintInput(thiccJonas[1]);
	pnb.PrintNumbers();
	return 0;
}