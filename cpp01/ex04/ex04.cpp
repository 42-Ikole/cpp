
#include <iostream>
#include <string>

int main()
{
    std::string string("HI THIS IS BRIAN");
    std::string *pointer = &string;
	std::string &ref = string;

    std::cout << *pointer << std::endl;
    std::cout << ref << std::endl;
    return (0);
}