#pragma once

#include <tuple>
#include <type_traits>
#include <optional>

/*!
 * @brief Group elements of toSplit into n/2 pairs, leaving one unpaired if there is an odd number of elements.
 * @param toSplit
 * @return tuple{smallerValues, largerValues, leftOverValue}
*/
template <class T, template<class ...> class Container>
std::tuple<Container<T>, Container<T>, std::optional<T> > GroupElementsIntoPairs(const Container<T>& toSplit);

/*!
 * @brief -.
 * @param list Only works if this list is sorted.
 * @param valueToInsert
*/
template <class T, template<class ...> class Container>
void BinaryInsert(Container<T>& list, T valueToInsert);

/*!
 * @brief Sorts toSort using the ford johnson algorithm https://en.wikipedia.org/wiki/Merge-insertion_sort
*/
template <class T, template<class ...> class Container>
void FordJohnsonSort(Container<T>& toSort);

#include "PmergeMe.ipp"
