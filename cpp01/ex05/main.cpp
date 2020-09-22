#include <iostream>
#include <string>
#include "Brain.hpp"
#include "Human.hpp"

int main()
{
    Human bob;

    std::cout << bob.identify() << std::endl;
    std::cout << bob.getbrain().identify() << std::endl;
    return (0);
}
