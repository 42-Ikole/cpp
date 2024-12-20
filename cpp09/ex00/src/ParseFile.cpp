
#include "ParseFile.hpp"

#include <tuple>
#include <string_view>
#include <exception>
#include <fstream>
#include <charconv>
#include <chrono>
#include <ctime>
#include <iostream>

namespace Parser
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

	template<ArithmeticType T>
	T ConvertStringToArithmeticType(
		const std::string_view& string,
		const std::optional<T>& minimumValue,
		const std::optional<T>& maximumValue)
	{
		T value = 0;
		const auto [ptr, errorCode] = std::from_chars(string.begin(), string.end(), value);
		if (errorCode != std::errc{} || ptr != string.end())
		{
			throw std::runtime_error("Could not convert `" + std::string(string) + "` to an arithmetic type: " + typeid(T).name());
		}

		if (minimumValue.has_value() && value < minimumValue.value())
		{
			throw std::runtime_error(
				"value is too low: " + std::to_string(value) +
				", The minimum value is " + std::to_string(minimumValue.value())
			);
		}

		if (maximumValue.has_value() && value > maximumValue.value())
		{
			throw std::runtime_error(
				"value is too high: " + std::to_string(value) +
				", The maximum value is " + std::to_string(maximumValue.value())
			);
		}

		std::cout << value << std::endl;

		return value;
	}

	bool IsValidDate(const std::string_view& date)
	{
		try
		{
			constexpr auto minimumPossibleYear = 1900;
			const auto currentTime = std::chrono::system_clock::now();
			auto currentTime_t = std::chrono::system_clock::to_time_t(currentTime);
			const auto currentTm = std::localtime(&currentTime_t);
			const auto currentYear = minimumPossibleYear + currentTm->tm_year;
			const auto currentMonth = currentTm->tm_mon + 1;
			const auto currentDay = currentTm->tm_mday + 1;

			const auto [yearString, remaining] = SplitStringOnDelimiter(date, "-");
			const auto dateYear = ConvertStringToArithmeticType<int>(yearString, minimumPossibleYear, currentYear);

			const auto [monthString, dayString] = SplitStringOnDelimiter(remaining, "-");
			constexpr auto minimumValidMonthValue = 1;
			const auto maximumValidMonthValue = (dateYear == currentYear) ? currentMonth : 12;
			const auto dateMonth = ConvertStringToArithmeticType<int>(monthString, minimumValidMonthValue, maximumValidMonthValue);

			constexpr auto minimumValidDayValue = 1;
			const auto maximumValidDayValue = (dateYear == currentYear && dateMonth == currentMonth) ? currentDay : 366; // Cant be asked checking if it was a leap year..
			(void)ConvertStringToArithmeticType<int>(dayString, minimumValidDayValue, maximumValidDayValue);
		}
		catch (const std::exception& e)
		{
			std::cerr << "Invalid date because: " << e.what() << std::endl;
			return false;
		}
		return true;
	}

	std::tuple<std::string_view, float> ParseLineIntoDateValuePair(
		const std::string& line,
		const std::string& delimiter,
		const std::optional<float>& minimumValue,
		const std::optional<float>& maximumValue)
	{
		const auto [date, valueString] = SplitStringOnDelimiter(line, delimiter);

		if (!IsValidDate(date))
		{
			throw std::runtime_error("Invalid date: `" + std::string(date) + "`, date must be in format Year-Month-Day");
		}

		const auto value = ConvertStringToArithmeticType<float>(
			valueString,
			minimumValue,
			maximumValue
		);
		return std::tuple{date, value};
	}

	std::map<std::string, float> ParseFileIntoDateValuePairs(
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

			std::map<std::string, float> dateValuePairs;
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
