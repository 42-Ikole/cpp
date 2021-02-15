
#include <string>
#include "Brain.hpp"

std::string	Brain::identify()
{
	unsigned long	address = (unsigned long)this;

	return ("0x" + std::to_string(address));
}
