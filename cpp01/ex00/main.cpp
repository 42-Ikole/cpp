
#include "Pony.hpp"

int main(void)
{
	ponyOnTheHeap();
	ponyOnTheStack();
	system("leaks a.out");
	return (0);
}
