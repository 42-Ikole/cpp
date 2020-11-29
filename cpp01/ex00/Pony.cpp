#include "Pony.hpp"
#include <iostream>
#include <string>
#include <new>

std::string	Pony::getName(void)
{
	return (this->name);
}

int		Pony::calcTime(void)
{
	int result = 0;

    for(int i = 0; i < 100; i += this->speed) {
        if (i > this->stamina) {
            this->stamina *= 2;
            for (int j = 0; j < this->cooldown; j++)
                result++;
        }
        result++;
	}
	return (result);
}

static void	race(Pony *pony1, Pony *pony2)
{
	int result1;
	int result2;

 	std::cout << pony1->getName() << " VS " << pony2->getName() << "\n";
	result1 = pony1->calcTime();
    result2 = pony2->calcTime();
    std::cout << ((result1 > result2) ? pony1->getName() : pony2->getName());
    std::cout << " Won by " << ((result1 - result2 < 0) ? result2 - result1 : result1 - result2) << " seconds!\n";
}

void    Pony::ponyOnTheHeap(void)
{
    Pony        *allocated_pony_1;
    Pony        *allocated_pony_2;

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
	race(allocated_pony_1, allocated_pony_2);
    delete allocated_pony_1;
    delete allocated_pony_2;
}

void    Pony::ponyOnTheStack(void)
{
    Pony        stack_pony_1;
    Pony        stack_pony_2;

    std::cout << "Testing ponies on the stack\n";
    stack_pony_1.name = "stack 1";
    stack_pony_1.speed = 8;
    stack_pony_1.stamina = 25;
    stack_pony_1.cooldown = 5;
    stack_pony_2.name = "stack 2";
    stack_pony_2.speed = 10;
    stack_pony_2.stamina = 20;
    stack_pony_2.cooldown = 5;
    race(&stack_pony_1, &stack_pony_2);
}
