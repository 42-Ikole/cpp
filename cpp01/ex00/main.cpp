
#include "Pony.hpp"

int main(void)
{
	ponyOnTheHeap();
	ponyOnTheStack();
	system("leaks a.out | grep total bytes leaked");
	return (0);
}
