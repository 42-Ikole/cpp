
#include "Serialization.hpp"
#include <iostream>

int main(void)
{
	srand(time(NULL));
	void *random = serialize();

	Data *data = deserialize(random);
	
	std::cout << "deserialized data: " << std::endl;
	printData(data);
	delete data;
	system("leaks serialize | grep 'leaks for'");
	return 0;
}
