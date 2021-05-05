#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>
#include <iterator>
#include <exception>

template<typename T>
typename T::iterator easyfind(T arr, int toFind)
{
	typename T::iterator fuck = std::find(arr.begin(), arr.end(), toFind);
	if (fuck == arr.end())
		throw std::exception();
	return fuck;
}

#endif
