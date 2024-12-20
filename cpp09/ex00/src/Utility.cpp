
#include "Utility.hpp"

#include <cstdio>
#include <stdexcept>
#include <cstring>
#include <chrono>

namespace Utility
{

	std::tuple<std::string_view, std::string_view> SplitStringOnDelimiter(const std::string_view& string, const std::string& delimiter)
	{
		const auto delimiterPos = string.find(delimiter);
		if (delimiterPos == std::string::npos)
		{
			throw std::runtime_error("Could not find delimiter `" + delimiter + "` in string: `" + std::string(string) + "`");
		}

		return std::tuple{
			std::string_view(&string.front(), delimiterPos),
			std::string_view(string.begin() + delimiterPos + delimiter.length(), string.end())
		};
	}

	std::tuple<std::string_view, std::string_view> SplitStringOnDelimiter(const std::string& string, const std::string& delimiter)
	{
		return SplitStringOnDelimiter(std::string_view(&string.front(), string.length()), delimiter);
	}

	std::time_t DateStringToTimeT(const std::string& date)
	{
		int yyyy, mm, dd;
		struct tm dateStruct;
		std::memset(&dateStruct, 0, sizeof(dateStruct));

		std::sscanf(date.c_str(), "%d-%d-%d", &yyyy, &mm, &dd);
		dateStruct.tm_year = yyyy;
		dateStruct.tm_mon = mm;
		dateStruct.tm_mday = dd;

		return mktime(&dateStruct);
	}

	size_t DifferenceInDays(const std::string& date1, const std::string& date2)
	{
		const auto time1 = DateStringToTimeT(date1);
		const auto time2 = DateStringToTimeT(date2);

		// We divide by the number of seconds because difftime's output is in seconds.
		constexpr auto numberOfSecondsInDay = 24 * 60 * 60;
		return std::abs(std::difftime(time1, time2)) / numberOfSecondsInDay;
	}

	std::tuple<int, Month, int> CurrentDate()
	{
		const auto currentTime = std::chrono::system_clock::now();
		auto currentTime_t = std::chrono::system_clock::to_time_t(currentTime);
		const auto currentTm = std::localtime(&currentTime_t);
		const auto currentYear = minimumPossibleYear + currentTm->tm_year;
		const auto currentMonth = currentTm->tm_mon + 1;
		const auto currentDay = currentTm->tm_mday;

		return std::tuple{currentYear, static_cast<Month>(currentMonth), currentDay};
	}

	size_t NumberOfDaysInMonth(const int year, const Month month)
	{
		switch (month)
		{
			case Month::January: return 31;
			case Month::February: return (year % 4) ? 28 : 29;
			case Month::March: return 31;
			case Month::April: return 30;
			case Month::May: return 31;
			case Month::June: return 30;
			case Month::July: return 31;
			case Month::August: return 31;
			case Month::September: return 30;
			case Month::October: return 31;
			case Month::November: return 30;
			case Month::December: return 31;
			default:
				throw std::runtime_error("Invalid month: " + std::to_string(static_cast<int>(month)) + " how did you manage this xd");
		}
	}

} /* namespace Utility */
