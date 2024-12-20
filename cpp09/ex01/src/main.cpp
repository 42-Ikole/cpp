
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
		std::deque<char> equationDeque;
		for (auto i = 1; i < argc; i++)
		{
			equationDeque.emplace_back(argv[i][0]);
		}
		std::cout << CalculateReversePolishNotation(equationDeque) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return 0;
}
