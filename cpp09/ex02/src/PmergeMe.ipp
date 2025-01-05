#include "PmergeMe.hpp"

#include <ranges>

template <class T, template<class ...> class Container>
std::tuple<Container<T>, Container<T>, std::optional<T> > GroupElementsIntoPairs(const Container<T>& toSplit)
{
	Container<T> smallerElements;
	Container<T> largerElements;
	std::optional<T> leftOverValue;

	constexpr auto pairChunkSize = 2;
	for (const auto& chunk : std::views::all(toSplit) | std::views::chunk(pairChunkSize))
	{
		if (chunk.size() < pairChunkSize)
		{
			leftOverValue = chunk.front();
			break;
		}
		if (chunk.front() < chunk.back())
		{
			smallerElements.emplace_back(chunk.front());
			largerElements.emplace_back(chunk.back());
		}
		else
		{
			smallerElements.emplace_back(chunk.back());
			largerElements.emplace_back(chunk.front());
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

	for (const auto& element : smallerElements)
	{
		BinaryInsert(toSort, element);
	}

	if (leftOverValue.has_value())
	{
		BinaryInsert(toSort, leftOverValue.value());
	}
}
