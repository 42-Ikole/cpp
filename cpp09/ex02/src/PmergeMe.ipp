#include "PmergeMe.hpp"

#include <ranges>
#include <algorithm>
#include <tuple>
#include <optional>

template <class T, template<class ...> class Container>
std::tuple<Container<T>, Container<T>, std::optional<T> > GroupElementsIntoPairs(const Container<T>& toSplit)
{
	Container<T> smallerElements;
	Container<T> largerElements;
	std::optional<T> leftOverValue;

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
	for (const auto& [firstValue, secondValueOpt] : std::views::all(toSplit) | std::views::chunk(pairChunkSize) | std::views::transform(rangeToTuple))
	{
		if (!secondValueOpt.has_value())
		{
			leftOverValue = firstValue;
			break;
		}
		const auto secondValue = secondValueOpt.value();
	
		if (firstValue < secondValue)
		{
			smallerElements.emplace_back(firstValue);
			largerElements.emplace_back(secondValue);
		}
		else
		{
			smallerElements.emplace_back(secondValue);
			largerElements.emplace_back(firstValue);
		}
	}
	return std::tuple{smallerElements, largerElements, leftOverValue};
}

template <class T, template<class ...> class Container>
void BinaryInsert(Container<T>& list, T valueToInsert)
{
	auto pos = std::upper_bound(list.begin(), list.end(), valueToInsert);
	list.insert(pos, valueToInsert);
}

template <class T, template<class ...> class Container>
void FordJohnsonSort(Container<T>& toSort)
{
	if (toSort.size() < 2)
	{
		return;
	}

	auto [smallerElements, largerElements, leftOverValue] = GroupElementsIntoPairs(toSort);
	toSort.clear();

	// Recursively sort the larger values.
	FordJohnsonSort(largerElements);
	
	// Create Sorted list with larger values
	for (const auto& element : largerElements)
	{
		toSort.emplace_back(element);
	}

	// Insert all smaller elements using binary search.
	for (const auto& element : smallerElements)
	{
		BinaryInsert(toSort, element);
	}

	if (leftOverValue.has_value())
	{
		BinaryInsert(toSort, leftOverValue.value());
	}
}
