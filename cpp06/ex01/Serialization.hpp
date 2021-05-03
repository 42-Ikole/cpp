
#ifndef SERIALIZATION_HPP
# define SERIALIZATION_HPP

#include <string>


struct Data
{
	std::string s1;
	int			n;
	std::string s2;
};

Data *	deserialize(void * raw);
void *	serialize(void);
void	printData(Data *data);

#endif 
