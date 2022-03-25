
#include "Convert.hpp"
#include <iostream>

int		main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "wrong number of arguments amigo!" << std::endl;
		return 0;
	}

	Convert c(argv[1]);
	std::cout << c;
	return 0;
}
