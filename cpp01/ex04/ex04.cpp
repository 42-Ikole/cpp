
#include <iostream>
#include <string>

int main()
{
    std::string ref("HI THIS IS BRIAN");
    const char  *pointer = ref.c_str();

    std::cout << pointer << "\n";
    std::cout << ref << "\n";
    return (0);
}