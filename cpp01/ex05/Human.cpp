
#include <string>
#include "Brain.hpp"
#include "Human.hpp"

std::string	Human::identify()
{
    return (this->_brain.identify());
}

Brain&  Human::getbrain()
{
    return (this->_brain);
}