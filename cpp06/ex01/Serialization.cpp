
#include "Serialization.hpp"
#include <iostream>
#include <string>


std::ostream&	operator << (std::ostream& o, const Data& d)
{
	o << "-----------------------\n" <<
		"address: " << (void*)&d << "\n" <<
		"s1 : " << d.s1 << "\n" <<
		"n  : " << d.n << "\n" <<
		"s2 : " << d.s2 << "\n" << std::endl;
	return o;
}

static std::string	randomString()
{
	std::string name;
	char 		consonents[] = {'b','c','d','f','g','h','j','k','l','m','n','p','q','r','s','t','v','w','x','z'};
	char 		vowels[] = {'a','e','i','o','u','y'};

	int random = rand() % 2;
	int count = 0;
	for (int i = 0; i < 8; i++) {
		if (random < 2 && count < 2) {
			name.push_back(consonents[rand() % 20]);
			count++;
		} else {
			name.push_back(vowels[rand() % 6]);
		}
		random = rand() % 2;
	}
	return (name);
}

uintptr_t serialize(void)
{
	Data *ret = new	Data;
	ret->s1 = randomString();
	ret->n = rand();
	ret->s2 = randomString();
	std::cout << "serialized data: " << std::endl;
	std::cout << *ret;
	return reinterpret_cast<uintptr_t>(ret);
}

Data * deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}

