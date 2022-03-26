
#ifndef ABC_HPP
# define ABC_HPP

# include "Base.hpp"
# include <ostream>

class A : public Base
{
};

std::ostream& operator << (std::ostream& o, const A& a);

class B : public Base
{
};

std::ostream& operator << (std::ostream& o, const B& b);

class C : public Base
{
};

std::ostream& operator << (std::ostream& o, const C& c);

#endif
