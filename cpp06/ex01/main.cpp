
#include "Serialization.hpp"
#include <iostream>

int main(void)
{
	srand(time(NULL));
	void *random = serialize();

	Data *data = deserialize(random);
	
	std::cout << "deserialized data: " << std::endl <<
		"-----------------------" << std::endl <<
		"s1 : " << data->s1 << std::endl <<
		"n  : " << data->n << std::endl <<
		"s2 : " << data->s2 << std::endl;
	delete data;
	// system("leaks a.out");
	return 0;
}
