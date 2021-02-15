
#include "Pony.hpp"
#include <iostream>
#include <string>
#include <new>

Pony::Pony(std::string name, int speed, int stamina, int cooldown) :
 _name(name), _speed(speed), _stamina(stamina), _cooldown(cooldown)
{
}

int		Pony::calcTime(void)
{
    int result = 0;

    for(int i = 0; i < 100; i += this->_speed) {
        if (i > this->_stamina) {
            this->_stamina *= 2;
            for (int j = 0; j < this->_cooldown; j++)
                result++;
        }
        result++;
    }
    return (result);
}

std::string Pony::getName(void)
{
    return (this->_name);
}

void    ponyOnTheHeap(void)
{
    Pony        *allocated_pony_1;
    Pony        *allocated_pony_2;
    int         result_1;
    int         result_2;

    try {
        allocated_pony_1 = new Pony("Pony 1", 10, 20, 5);
        allocated_pony_2 = new Pony("Pony 2", 8, 25, 5);
    }
    catch(std::bad_alloc& ba) {
        return ;
    }
    
    std::cout << "Testing ponies on the heap\n";
    // Announce race
    std::cout << allocated_pony_1->getName() << " VS " << allocated_pony_2->getName() << "\n";
    //calculate time of horse 1
    result_1 = allocated_pony_1->calcTime();
    //calculate time of horse 2
    result_2 = allocated_pony_2->calcTime();
    std::cout << ((result_1 > result_2) ? allocated_pony_1->getName() : allocated_pony_2->getName());
    std::cout << " Won by " << ((result_1 - result_2 < 0) ? result_2 - result_1 : result_1 - result_2) << " seconds!\n" << std::endl;
    delete allocated_pony_1;
    delete allocated_pony_2;
}

void        ponyOnTheStack(void)
{
    Pony        stack_pony_1("Stack 1", 8, 25, 5);
    Pony        stack_pony_2("Stack 2", 10, 20, 5);
    int         result_1;
    int         result_2;

    std::cout << "Testing ponies on the stack\n";
    // Announce race
    std::cout << stack_pony_1.getName() << " VS " << stack_pony_2.getName() << "\n";
    //calculate time of horse 1
    result_1 = stack_pony_1.calcTime();
    //calculate time of horse 2
    result_2 = stack_pony_2.calcTime();
    std::cout << ((result_1 > result_2) ? stack_pony_1.getName() : stack_pony_2.getName());
    std::cout << " Won by " << ((result_1 - result_2 < 0) ? result_2 - result_1 : result_1 - result_2) << " seconds!\n" << std::endl;
}
