#include <iostream>
#include <string>

int main(int num_arg, char* str[])
{
    if (num_arg == 1) {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
        return (0);
    }
    for (int i = 1; i < num_arg; i++) {
        for (int j = 0; str[i][j]; j++) {
            std::cout << (char)std::toupper(str[i][j]);
        }
    }
    std::cout << std::endl;
    return (0);
}
