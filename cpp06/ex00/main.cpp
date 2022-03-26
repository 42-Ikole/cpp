
#include "Convert.hpp"
#include <iostream>

int		main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "wrong number of arguments amigo!" << std::endl;
		return 0;
	}

	try {
		Convert c(argv[1]);
		std::cout << c;
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
