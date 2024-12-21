
#include "ReversePolishNotationCalculator.hpp"

#include <iostream>

int main(int argc, const char* const* argv)
{
	if (argc < 4)
	{
		std::cerr << "You need to give atleast 3 arguments for a valid polish notation calculation" << std::endl;
		return 1;
	}

	try
	{
		std::queue<char> equationQueue;
		for (auto i = 1; i < argc; i++)
		{
			equationQueue.emplace_back(argv[i][0]);
		}
		std::cout << CalculateReversePolishNotation(equationQueue) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return 0;
}
