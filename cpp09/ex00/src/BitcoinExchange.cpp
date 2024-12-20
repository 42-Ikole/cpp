#include "BitcoinExchange.hpp"
#include "ParseFile.hpp"

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
	auto greaterOrEqualItr = exchangeRates.lower_bound(date);
		
	if (greaterOrEqualItr == exchangeRates.end())
	{
		greaterOrEqualItr--;
	}

	// This is either the correct date or the only date in the database.
	if (greaterOrEqualItr == exchangeRates.begin())
	{
		return CalculateExchange(greaterOrEqualItr->second, valueToExchange);
	}
	
	const auto smallerItr = std::prev(greaterOrEqualItr);
	// Doing a lexicographical compare on the dates because that should work.
	if (smallerItr->first.compare(greaterOrEqualItr->first) < 0)
	{
	}
		return 1;
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
		const auto exhangedValue = CalculateExchangeWithClosestDate(date, valueToExchange);
		std::cout << date << " => " << valueToExchange << " = " << exhangedValue << '\n';
	}
}
