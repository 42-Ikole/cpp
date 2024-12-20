#pragma once

#include "Utility.hpp"

#include <map>
#include <string>
#include <tuple>
#include <optional>
#include <string_view>

namespace Parser
{
	static constexpr auto csvDelimiter = ",";

	/*!
	 * @brief
	 * @param yearString
	 * @return
	*/
	int GetYear(const std::string_view& yearString);

	/*!
	 * @brief
	 * @param monthString
	 * @param year
	 * @return
	*/
	Month GetMonth(const std::string_view& monthString, const int year);

	/*!
	 * @brief
	 * @param dayString
	 * @param year
	 * @param month
	 * @return
	*/
	bool GetDay(const std::string_view& dayString, const int year, const Month month);

	/*!
	 * @brief Checks wheter the date is in the propper format and possible.
	 * @param date
	 * @return optional<reasonInvalidDate>
	*/
	std::optional<std::string> ValidateDate(const std::string_view& date);

	/*!
	 * @brief
	 * @param line
	 * @param delimiter
	 * @param minimumValue
	 * @param maximumValue
	 * @return
	*/
	std::tuple<std::string_view, float> ParseLineIntoDateValuePair(
		const std::string& line,
		const std::string& delimiter,
		const std::optional<float>& minimumValue = std::nullopt,
		const std::optional<float>& maximumValue = std::nullopt
	);

	/*!
	 * @brief Parses files with format "date <delimiter> value" into a map of date value pairs.
	 * @param dataFileName
	 * @param delimiter
	 * @param numberOfLinesInHeader
	 * @param errorOnDuplicates
	 * @param stopAtParseError
	 * @param minimumValue
	 * @param maximumValue
	 * @return
	*/
	std::multimap<std::string, float> ParseFileIntoDateValuePairs(
		const std::string& dataFileName,
		const std::string& delimiter,
		const size_t numberOfLinesInHeader,
		const bool errorOnDuplicates = true,
		const bool stopAtParseError = true,
		const std::optional<float>& minimumValue = std::nullopt,
		const std::optional<float>& maximumValue = std::nullopt
	);

};
