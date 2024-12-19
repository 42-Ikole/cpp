#pragma once

#include <map>
#include <string>
#include <tuple>
#include <optional>

/*!
 * @brief -.
*/
template<class T>
concept ArithmeticType = std::is_arithmetic_v<T>;

namespace Parser
{
	static constexpr auto csvDelimiter = ",";

	/*!
	 * @brief Parses the dataFile into a map for easy lookup.
	 * @param dataFileName
	 * @return
	*/
	std::map<std::string, float> ExchangeRatesFromDataFile(const std::string& dataFileName);

	/*!
	 * @brief Splits string into two strings based on delimiter.
	 * @param string
	 * @param delimiter
	*/
	std::tuple<std::string_view, std::string_view> SplitStringOnDelimiter(const std::string_view& string, const std::string& delimiter);

	/*!
	 * @brief Splits string into two strings based on delimiter.
	 * @param string
	 * @param delimiter
	*/
	std::tuple<std::string_view, std::string_view> SplitStringOnDelimiter(const std::string& string, const std::string& delimiter);

	/*!
	 * @brief -.
	 * @tparam T
	 * @param string
	 * @param minimumValue
	 * @param maximumValue
	 * @return
	*/
	template<ArithmeticType T>
	T ConvertStringToArithmeticType(
		const std::string_view& string,
		const std::optional<T>& minimumValue = std::nullopt,
		const std::optional<T>& maximumValue = std::nullopt);

	/*!
	 * @brief Checks wheter the date is in the propper format and possible.
	 * @param date
	 * @return
	*/
	bool IsValidDate(const std::string_view& date);

	/*!
	 * @brief parses files with format "date <delimiter> value"
	 * @param dataFileName
	 * @param delimiter
	 * @param minimumValue
	 * @param maximumValue
	 * @return
	*/
	std::map<std::string, float> ParseFileIntoDateValuePairs(
		const std::string& dataFileName,
		const std::string& delimiter,
		const std::optional<float>& minimumValue = std::nullopt,
		const std::optional<float>& maximumValue = std::nullopt
	);

};
