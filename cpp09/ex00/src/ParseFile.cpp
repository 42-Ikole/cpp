
#include "ParseFile.hpp"
#include "Utility.hpp"

#include <tuple>
#include <exception>
#include <fstream>
#include <iostream>

namespace Parser
{
	int GetYear(const std::string_view& yearString)
	{
		const auto [currentYear, _, __] = Utility::CurrentDate();
		return Utility::ConvertStringToArithmeticType<int>(yearString, Utility::minimumPossibleYear, currentYear);
	}

	Month GetMonth(const std::string_view& monthString, const int year)
	{
		const auto [currentYear, currentMonth, _] = Utility::CurrentDate();

		constexpr auto minimumValidMonthValue = 1;
		const auto maximumValidMonthValue = (year == currentYear) ? currentMonth : Month::December;
		return static_cast<Month>(
				Utility::ConvertStringToArithmeticType<int>(
					monthString,
					minimumValidMonthValue,
					static_cast<int>(maximumValidMonthValue
				)
			)
		);
	}

	bool GetDay(const std::string_view& dayString, const int year, const Month month)
	{
		const auto [currentYear, currentMonth, currentDayInYear] = Utility::CurrentDate();

		constexpr auto minimumValidDayValue = 1;
		auto maximumValidDayValue = Utility::NumberOfDaysInMonth(year, month);
		if (year == currentYear && month == currentMonth)
		{
			maximumValidDayValue = currentDayInYear;
		}
		return Utility::ConvertStringToArithmeticType<int>(dayString, minimumValidDayValue, maximumValidDayValue);
	}

	std::optional<std::string> ValidateDate(const std::string_view& date)
	{
		try
		{
			const auto [yearString, remaining] = Utility::SplitStringOnDelimiter(date, "-");
			const auto year = GetYear(yearString);

			const auto [monthString, dayString] = Utility::SplitStringOnDelimiter(remaining, "-");
			const auto month = GetMonth(monthString, year);

			(void)GetDay(dayString, year, month);
		}
		catch (const std::exception& e)
		{
			return e.what();
		}
		return std::nullopt;
	}

	std::tuple<std::string_view, float> ParseLineIntoDateValuePair(
		const std::string& line,
		const std::string& delimiter,
		const std::optional<float>& minimumValue,
		const std::optional<float>& maximumValue)
	{
		const auto [date, valueString] = Utility::SplitStringOnDelimiter(line, delimiter);

		const auto invalidReasonOpt = ValidateDate(date);
		if (invalidReasonOpt.has_value())
		{
			throw std::runtime_error(
				"Invalid date: `" + std::string(date) + "`"
				"because: " + invalidReasonOpt.value() +
				", date must be in format Year-Month-Day"
			);
		}

		const auto value = Utility::ConvertStringToArithmeticType<float>(
			valueString,
			minimumValue,
			maximumValue
		);
		return std::tuple{date, value};
	}

	std::multimap<std::string, float> ParseFileIntoDateValuePairs(
		const std::string& dataFileName,
		const std::string& delimiter,
		const size_t numberOfLinesInHeader,
		const bool errorOnDuplicates,
		const bool stopAtParseError,
		const std::optional<float>& minimumValue,
		const std::optional<float>& maximumValue)
	{
		try
		{
			std::ifstream dataFile(dataFileName);
			if (!dataFile.good())
			{
				throw std::runtime_error("Could not open file for reading");
			}

			for (size_t i = 0; i < numberOfLinesInHeader; i++)
			{
				std::string ignore;
				std::getline(dataFile, ignore);
			}

			std::multimap<std::string, float> dateValuePairs;
			for (std::string line; std::getline(dataFile, line); )
			{
				try
				{
					const auto& [date, valueString] = ParseLineIntoDateValuePair(line, delimiter, minimumValue, maximumValue);
					
					if (errorOnDuplicates && dateValuePairs.contains(std::string(date)))
					{
						throw std::runtime_error("Date `" + std::string(date) + "` is contained multiple times");
					}
					dateValuePairs.emplace(date, valueString);
				}
				catch (const std::exception& e)
				{
					if (stopAtParseError)
					{
						std::rethrow_exception(std::current_exception());
					}
					std::cerr << "Error: " << e.what() << '\n';
				}
			}
			return dateValuePairs;
		}
		catch (const std::exception& e)
		{
			throw std::runtime_error("Fatal error parsing file `" + dataFileName + "`: " + e.what());
		}
	}
}
