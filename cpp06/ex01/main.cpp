
#include "Serialization.hpp"
#include <iostream>

int main(void)
{
	srand(time(NULL));
	uintptr_t random = serialize();

	Data *data = deserialize(random);
	
	std::cout << "deserialized data: " << std::endl;
	std::cout << *data;
	delete data;
	system("leaks serialize | grep 'leaks for'");
	return 0;
}
