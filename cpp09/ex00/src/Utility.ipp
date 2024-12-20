
#include "Utility.hpp"

#include <charconv>
#include <stdexcept>


namespace Utility
{

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

		return value;
	}

}
