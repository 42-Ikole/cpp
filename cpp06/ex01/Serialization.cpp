
#include "Serialization.hpp"
#include <iostream>
#include <string>


void	printData(Data *data)
{
	std::cout <<	"-----------------------" << std::endl <<
					"s1 : " << data->s1 << std::endl <<
					"n  : " << data->n << std::endl <<
					"s2 : " << data->s2 << std::endl << std::endl;;
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

void * serialize(void)
{
	Data *ret = new	Data;
	ret->s1 = randomString();
	ret->n = rand();
	ret->s2 = randomString();
	std::cout << "serialized data: " << std::endl;
	printData(ret);
	return reinterpret_cast<void*>(ret);
}

Data * deserialize(void * raw)
{
	Data *ret = reinterpret_cast<Data*>(raw);
	return ret;
}

