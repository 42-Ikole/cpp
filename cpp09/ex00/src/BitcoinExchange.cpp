#include "BitcoinExchange.hpp"
#include "ParseFile.hpp"
#include "Utility.hpp"

#include <iostream>

BitcoinExchange::BitcoinExchange(const std::string& dataFileName)
	: exchangeRates(
		Parser::ParseFileIntoDateValuePairs(
			dataFileName,
			Parser::csvDelimiter,
			numberOfLinesInHeader
		)
	)
{
}

float BitcoinExchange::CalculateExchange(float valueToExchange, float exchangeRate) const
{
	return valueToExchange * exchangeRate;
}

float BitcoinExchange::CalculateExchangeWithClosestDate(const std::string& date, float valueToExchange) const
{
	auto itr = exchangeRates.lower_bound(date);

	if (itr == exchangeRates.begin())
	{
		throw std::runtime_error("Could not find exchange rate for " + date + " or earlier, the first known exchange rate is " + itr->first);
	}

	if (itr == exchangeRates.end() || itr->first != date)
	{
		itr--;
		std::cerr << "Could not find exchange rate on: " << date << ", using exchange rate from ";
		std::cerr << Utility::DifferenceInDays(date, itr->first) << " days earlier\n";
	}
	return CalculateExchange(valueToExchange, itr->second);
}

void BitcoinExchange::CalculateAndPrintExchanges(const std::string& inputFileName) const
{
	constexpr auto delimiter = " | ";
	constexpr auto errorOnDuplicates = false;
	constexpr auto stopOnParseErrors = false;
	const auto& valuesToExchange = Parser::ParseFileIntoDateValuePairs(
		inputFileName,
		delimiter,
		numberOfLinesInHeader,
		errorOnDuplicates,
		stopOnParseErrors,
		minimumExchangeValue,
		maximumExchangeValue
	);

	for (const auto& [date, valueToExchange] : valuesToExchange)
	{
		try
		{
			const auto exhangedValue = CalculateExchangeWithClosestDate(date, valueToExchange);
			std::cout << date << " => " << valueToExchange << " = " << exhangedValue << '\n';
		}
		catch (const std::exception& e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
		}
	}
}
