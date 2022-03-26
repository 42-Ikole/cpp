
# include "ABC.hpp"

std::ostream& operator << (std::ostream& o, const A& a)
{
	(void)a;
	o << "A" << std::endl;
	return o;
}

std::ostream& operator << (std::ostream& o, const B& b)
{
	(void)b;
	o << "B" << std::endl;
	return o;
}

std::ostream& operator << (std::ostream& o, const C& c)
{
	(void)c;
	o << "C" << std::endl;
	return o;
}