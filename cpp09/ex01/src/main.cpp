
#include "ReversePolishNotationCalculator.hpp"

#include <iostream>

int main(int argc, const char* const* argv)
{
	if (argc != 2)
	{
		std::cerr << "You need to pass the quation as argument to the program" << std::endl;
		return 1;
	}

	try
	{
		const auto equationQueue = CreateEquationQueue(argv[1]);
		std::cout << CalculateReversePolishNotation(equationQueue) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	return 0;
}
