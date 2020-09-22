
#include <string>
#include "Brain.hpp"
#include "Human.hpp"

std::string	Human::identify()
{
    return (brain.identify());
}

Brain&  Human::getbrain()
{
    return (brain);
}