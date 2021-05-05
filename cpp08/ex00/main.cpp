
#include "easyfind.hpp"
#include <vector>
#include <iostream>
#include <list>

int main(void)
{
	int val[] = {1, 2, 5, 7, 8};
	try {
		std::vector<int> vec;
		vec.assign(val, val + 5);
		std::cout << "vec finding 2: " << *easyfind(vec, 2) << std::endl;
		std::cout << "vec finding 3: " << *easyfind(vec, 3) << std::endl;
	} catch (std::exception & msg) {
		std::cerr << "cannot find the number m8" << std::endl;
	}

	try {
		std::list<int> lst;
		lst.assign(val, val + 5);
		std::cout << "lst finding 2: " << *easyfind(lst, 2) << std::endl;
		std::cout << "lst finding 3: " << *easyfind(lst, 3) << std::endl;
	} catch (std::exception & msg) {
		std::cerr << "cannot find the number m8" << std::endl;
	}
}