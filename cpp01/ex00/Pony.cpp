#include "Pony.hpp"
#include <iostream>
#include <string>
#include <new>

void    Pony::ponyOnTheHeap(void)
{
    Pony        *allocated_pony_1;
    Pony        *allocated_pony_2;
    int         result_1 = 0;
    int         result_2 = 0;

    try {
        allocated_pony_1 = new Pony;
        allocated_pony_2 = new Pony;
    }
    catch(std::bad_alloc& ba) {
        return ;
    }
    
    std::cout << "Testing ponies on the heap\n";
    allocated_pony_1->name = "Pony 1";
    allocated_pony_1->speed = 10;
    allocated_pony_1->stamina = 20;
    allocated_pony_1->cooldown = 5;
    allocated_pony_2->name = "Pony 2";
    allocated_pony_2->speed = 8;
    allocated_pony_2->stamina = 25;
    allocated_pony_2->cooldown = 5;
    //race
    std::cout << allocated_pony_1->name << " VS " << allocated_pony_2->name << "\n";
    //calculate time of horse 1
    for(int i = 0; i < 100; i += allocated_pony_1->speed) {
        if (i > allocated_pony_1->stamina) {
            allocated_pony_1->stamina *= 2;
            for (int j = 0; j < allocated_pony_1->cooldown; j++)
                result_1++;
        }
        result_1++;
    }
    //calculate time of horse 2
    for(int i = 0; i < 100; i += allocated_pony_2->speed) {
        if (i > allocated_pony_2->stamina) {
            allocated_pony_2->stamina *= 2;
            for (int j = 0; j < allocated_pony_2->cooldown; j++)
                result_2++;
        }
        result_2++;
    }
    std::cout << ((result_1 > result_2) ? allocated_pony_1->name : allocated_pony_2->name);
    std::cout << " Won by " << ((result_1 - result_2 < 0) ? result_2 - result_1 : result_1 - result_2) << " seconds!\n";
    delete allocated_pony_1;
    delete allocated_pony_2;
}

void    Pony::ponyOnTheStack(void)
{
    Pony        stack_pony_1;
    Pony        stack_pony_2;
    int         result_1 = 0;
    int         result_2 = 0;

    std::cout << "Testing ponies on the stack\n";
    stack_pony_1.name = "stack 1";
    stack_pony_1.speed = 8;
    stack_pony_1.stamina = 25;
    stack_pony_1.cooldown = 5;
    stack_pony_2.name = "stack 2";
    stack_pony_2.speed = 10;
    stack_pony_2.stamina = 20;
    stack_pony_2.cooldown = 5;
    //race
    std::cout << stack_pony_1.name << " VS " << stack_pony_2.name << "\n";
    //calculate time of horse 1
    for(int i = 0; i < 100; i += stack_pony_1.speed) {
        if (i > stack_pony_1.stamina) {
            stack_pony_1.stamina *= 2;
            for (int j = 0; j < stack_pony_1.cooldown; j++)
                result_1++;
        }
        result_1++;
    }
    //calculate time of horse 2
    for(int i = 0; i < 100; i += stack_pony_2.speed) {
        if (i > stack_pony_2.stamina) {
            stack_pony_2.stamina *= 2;
            for (int j = 0; j < stack_pony_2.cooldown; j++)
                result_2++;
        }
        result_2++;
    }
    std::cout << ((result_1 > result_2) ? stack_pony_1.name : stack_pony_2.name);
    std::cout << " Won by " << ((result_1 - result_2 < 0) ? result_2 - result_1 : result_1 - result_2) << " seconds!\n";
}
