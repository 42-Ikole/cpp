
#include <string>
#include "Brain.hpp"

std::string	Brain::identify()
{
	unsigned long	address = (unsigned long)this;
	std::string		ret("0x");

	ret.append(std::to_string(address));
	return (ret);
}
