
#include <iostream>
#include "span.hpp"

int main()
{
	Span sp = Span(7);
	try {
		sp.addNumber(5);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		sp.addNumber(INT_MAX);
		sp.addNumber(INT_MIN);
		sp.addNumber(12);
	}	catch (std::exception & msg) {
		std::cout << msg.what() << std::endl;
	}
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	Span spun = Span(1);
	try {
		spun.addNumber(42);
		std::cout << spun.shortestSpan() << std::endl;
	std::cout << spun.longestSpan() << std::endl;
	}	catch (std::exception & msg) {
		std::cout << msg.what() << std::endl;
	}
	
	Span sprrt = Span(43);
	std::vector<int> brrt;
	try {
		int lst[42 + 1];
		for (int i = 0; i < 42; i++)
			lst[i] = i;
		lst[42] = 6969;
		brrt.assign(lst, lst + 43);
		sprrt.addNumber(brrt.begin(), brrt.end());
		std::cout << sprrt.longestSpan() << std::endl;
	}	catch (std::exception & msg) {
		std::cout << msg.what() << std::endl;
	}
	try {
		Span nope = Span(10);
		nope.addNumber(brrt.begin(), brrt.end());
	}	catch (std::exception & msg) {
		std::cout << msg.what() << std::endl;
	}
}