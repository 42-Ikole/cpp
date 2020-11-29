
#include "Pony.hpp"

int main(void)
{
	Pony thehekku;

	thehekku.ponyOnTheHeap();
    thehekku.ponyOnTheStack();
	system("leaks a.out | grep 'total leaked bytes'");
    return (0);
}
