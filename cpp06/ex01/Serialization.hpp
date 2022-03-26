
#ifndef SERIALIZATION_HPP
# define SERIALIZATION_HPP

# include <string>
# include <ostream>

struct Data
{
	std::string s1;
	int			n;
	std::string s2;
};

std::ostream&	operator << (std::ostream& o, const Data& d);

Data *		deserialize(uintptr_t raw);
uintptr_t	serialize(void);

#endif 
