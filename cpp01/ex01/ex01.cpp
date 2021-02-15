
#include <string>
#include <iostream>

//goed checken niet gecopypaste!
void        memoryLeak()
{
    std::string*    panther = new std::string("String panther");

    std::cout << *panther << std::endl;
    delete panther;
}

int main()
{
    memoryLeak();
    system("leaks a.out");
}