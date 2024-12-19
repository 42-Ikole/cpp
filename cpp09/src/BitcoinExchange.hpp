#pragma once

#include <string>
#include <map>


class BitcoinExchange
{
private:

	static constexpr float minimumExchangeRate = 0; /*!< -. */
	static constexpr float maximumExchangeRate = 1000; /*!< -. */

	const std::map<std::string, float> exchangeRates; /* map<date, exchangeRate> */

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
	 * @param rhs
	 * @return
	*/
	BitcoinExchange& operator = (const BitcoinExchange& rhs) = default;

	/*!
	 * @brief
	 * @param inputFileName
	*/
	void CalculateAndPrintExchanges(const std::string& inputFileName) const;

};
