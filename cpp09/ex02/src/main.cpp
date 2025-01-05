
#include "PmergeMe.hpp"

#include <iostream>

int main(void)
{
	std::vector<int> v {5, 3, 4, 6, 2, 0, 1};

	FordJohnsonSort(v);

	for (const auto& p : v)
    {
        std::cout << p << ", ";
    }
    std::cout << std::endl;

}
