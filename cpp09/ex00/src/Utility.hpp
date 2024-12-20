#pragma once

#include <string>
#include <optional>
#include <ctime>
#include <tuple>
#include <string_view>

/*!
 * @brief
*/
enum class Month
{
	January = 1,
	February = 2,
	March = 3,
	April = 4,
	May = 5,
	June = 6,
	July = 7,
	August = 8,
	September = 9,
	October = 10,
	November = 11,
	December = 12
};

namespace Utility
{
	/*!
	* @brief -.
	*/ 
	template<class T>
	concept ArithmeticType = std::is_arithmetic_v<T>;

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
	 * @brief Converts date with format yyyy-mm-dd to time_t.
	 * @note Assumes the date string is valid.
	 * @param date
	 * @return
	*/
	std::time_t DateStringToTimeT(const std::string& date);

	/*!
	 * @brief -.
	 * @param date1
	 * @param date2
	 * @return
	*/
	size_t DifferenceInDays(const std::string& date1, const std::string& date2);

	static constexpr auto minimumPossibleYear = 1900;

	/*!
	 * @brief
	 * @return tuple<year, month, day>
	*/
	std::tuple<int, Month, int> CurrentDate();

	/*!
	 * @brief
	 * @param year
	 * @param month
	 * @return
	*/
	size_t NumberOfDaysPassedBeforeMonth(const int year, const Month month);

	/*!
	 * @brief
	 * @param year
	 * @param month
	 * @return
	*/
	size_t NumberOfDaysInMonth(const int year, const Month month);

} /* namespace Utility */

#include "Utility.ipp"
