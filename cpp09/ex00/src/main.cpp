
#include "BitcoinExchange.hpp"

#include <iostream>

int main(int argc, const char* const* argv)
{
	if (argc != 2)
	{
		std::cerr << "To run this program you need to provide a database file as argument." << std::endl;
		return 1;
	}

	try
	{
		const BitcoinExchange bitcoinExchange("data.csv");

		bitcoinExchange.CalculateAndPrintExchanges(argv[1]);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " <<  e.what() << std::endl;
		return 1;
	}

	return 0;
}
