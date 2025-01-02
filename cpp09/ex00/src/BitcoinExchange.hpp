#pragma once

#include <string>
#include <map>
#include <limits>

class BitcoinExchange
{
private:

	static constexpr float minimumExchangeValue = std::numeric_limits<float>::min(); /*!< -. */
	static constexpr float maximumExchangeValue = 1000; /*!< -. */
	static constexpr size_t numberOfLinesInHeader = 1; /*!< -. */

	const std::multimap<std::string, float> exchangeRates; /* map<date, exchangeRate> */

	/*!
	 * @brief
	 * @param valueToExchange
	 * @param exchangeRate
	*/
	float CalculateExchange(float valueToExchange, float exchangeRate) const;

	/*!
	 * @brief
	 * @param date
	 * @param valueToExchange
	 * @return
	*/
	float CalculateExchangeWithClosestDate(const std::string& date, float valueToExchange) const;

public:

	/*!
	 * @brief
	 * @param dataFileName
	*/
	BitcoinExchange(const std::string& dataFileName);

	/*!
	 * @brief
	 * @param rhs
	*/
	BitcoinExchange(const BitcoinExchange& rhs) = default;

	/*!
	 * @brief
	*/
	~BitcoinExchange() = default;

	/*!
	 * @brief
	 * @param rhs
	 * @return
	*/
	BitcoinExchange& operator = (const BitcoinExchange& rhs) = delete;

	/*!
	 * @brief
	 * @param inputFileName
	*/
	void CalculateAndPrintExchanges(const std::string& inputFileName) const;

};
