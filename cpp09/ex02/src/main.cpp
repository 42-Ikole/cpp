
#include "PmergeMe.hpp"

#include <iostream>
#include <chrono>
#include <functional>
#include <sstream>
#include <ranges>
#include <charconv>
#include <vector>
#include <list>
#include <deque>

/*!
 * @brief -.
*/ 
template<class T>
concept ArithmeticType = std::is_arithmetic_v<T>;

/*!
 * @brief- .
*/
template<ArithmeticType T>
static T ConvertStringToArithmeticType(
	const std::string_view& string,
	const T& minimumValue = std::numeric_limits<T>::lowest(),
	const T& maximumValue = std::numeric_limits<T>::max())
{
	T value = 0;
	const auto [ptr, errorCode] = std::from_chars(string.begin(), string.end(), value);
	if (errorCode != std::errc{})
	{
		std::stringstream errorMessage;
		errorMessage << "Could not convert `" << string << "` to an arithmetic type: " << typeid(T).name()
					 << " because: (system error) " << std::make_error_code(errorCode);
		throw std::runtime_error(errorMessage.str());
	}
	if (ptr != string.end())
	{
		throw std::runtime_error(
			"Could not convert all characters in `" + std::string(string) +
			"` to an arithmetic type: " + typeid(T).name()
		);
	}

	if (value < minimumValue)
	{
		throw std::runtime_error(
			"value is too low: " + std::to_string(value) +
			", The minimum value is " + std::to_string(minimumValue)
		);
	}

	if (value > maximumValue)
	{
		throw std::runtime_error(
			"value is too high: " + std::to_string(value) +
			", The maximum value is " + std::to_string(maximumValue)
		);
	}

	return value;
}

/*!
 * @brief -.
*/
template <class T, template<class ...> class Container>
bool IsSortedAscending(const Container<T>& container)
{
	if (container.empty())
	{
		return true;
	}

	const auto rangeToTuple = [](const auto&& range) -> std::tuple<T, std::optional<T> >
	{
		auto itr = range.begin();
		auto firstValue = *itr;
		itr++;
		std::optional<T> secondValue;
		if (itr != range.end())
		{
			secondValue = *itr;
		}
		return std::tuple{firstValue, secondValue};
	};

	constexpr auto pairChunkSize = 2;
	T previousValue = container.front();
	bool isSorted = true;
	for (const auto& [leftValue, rightValueOpt] : std::views::all(container) | std::views::chunk(pairChunkSize) | std::views::transform(rangeToTuple))
	{
		isSorted &= previousValue <= leftValue;
		if (rightValueOpt.has_value())
		{
			isSorted &= leftValue <= rightValueOpt.value();
		}
	}
	return isSorted;
}

/*!
 * @brief -.
 * @param parameter Will pass a copy of this for each repetition of the benchmark.
 * @param numberOfRepetitions
 * @return tuple<totalTimeInMilliSeconds, averageTimeInMicroSeconds>
*/
template<class Container>
static std::tuple<
	std::chrono::milliseconds,
	std::chrono::microseconds
> BenchmarkFunction(
	const Container& containerToSort,
	const size_t numberOfRepetitions = 10'000)
{
	std::chrono::microseconds totalTime(0);
	for (auto r = numberOfRepetitions; r > 0; r--)
	{
		// Making a copy so we cna re-use containerToSort
		auto toSort = containerToSort;

		auto startTime = std::chrono::steady_clock::now();
		FordJohnsonSort(toSort);
		auto endTime = std::chrono::steady_clock::now();
		
		totalTime += std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);
		
		if (!IsSortedAscending(toSort))
		{
			throw std::runtime_error("Container was not sorted");
		}
	}
	const auto averageTime = totalTime / numberOfRepetitions;
	return std::tuple{
		std::chrono::duration_cast<std::chrono::milliseconds>(totalTime),
		averageTime
	};
}

/*!
 * @brief -.
 * @param inputValuesString
 * @return
*/
static std::vector<int> ParseInputToVector(char** inputValuesString, int numberOfNumbers)
{
	std::vector<int> parsedValues;
	for (auto i = 0; i < numberOfNumbers; i++)
	{
		constexpr auto minimumValue = 0;
		parsedValues.emplace_back(ConvertStringToArithmeticType<int>(inputValuesString[i], minimumValue));
	}
	return parsedValues;
}

/*!
 * @brief -.
 * @param totalTime
 * @param averageTime
 * @param testedContainer
*/
static void PrintBenchMarkResults(
	const std::chrono::milliseconds& totalTime,
	const std::chrono::microseconds& averageTime,
	const std::string& testedContainer)
{
	std::cout << "Bench mark results for " << testedContainer << ": total time " << totalTime <<
				 ", average time " << averageTime << std::endl; 
}

template <class Container>
static void RunAndPrintBenchmark(const Container& container, const std::string& containerName)
{
	const auto& [totalTime, averageTime] = BenchmarkFunction(container);
	PrintBenchMarkResults(totalTime, averageTime, containerName);
}

int main(int argc, char** argv)
{
	if (argc < 2)
	{
		std::cerr << "Cannot run program without parameters, program requires atleast one parameter" << std::endl;;
		return 1;
	}

	try
	{
		const auto inputVector = ParseInputToVector(argv + 1, argc - 1);
		RunAndPrintBenchmark(inputVector, "std::vector");

		const std::deque<int> inputDeque(inputVector.begin(), inputVector.end());
		RunAndPrintBenchmark(inputDeque, "std::deque");

		const std::list<int> inputList(inputVector.begin(), inputVector.end());
		RunAndPrintBenchmark(inputList, "std::list");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}
