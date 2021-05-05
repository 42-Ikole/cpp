
#include <iterator>
#include <algorithm>
#include <vector>
#include <math.h>
#include "span.hpp"

Span::Span(unsigned int N)
{
	this->_N = N;
}

Span::Span(const Span &tbc) : _N(0)
{
	*this = tbc;
}

Span::~Span()
{}

Span & Span::operator = (const Span &tba)
{
	this->_N = tba._N;
	this->_arr = tba._arr;
	return *this;
}

void	Span::addNumber(const int nb)
{
	if (this->_arr.size() < this->_N) {
		this->_arr.push_back(nb);
		std::sort(this->_arr.begin(), this->_arr.end());
	} else
		throw ListFull();
}

void	Span::addNumber(const std::vector<int>::iterator begin, const std::vector<int>::iterator end)
{
	if (this->_N - this->_arr.size() >= (unsigned long)std::distance(begin, end))
	{
		this->_arr.insert(this->_arr.begin(), begin, end);
		std::sort(this->_arr.begin(), this->_arr.end());
	} else
		throw NoSpace();
}

size_t		Span::shortestSpan(void)
{
	if (this->_arr.size() <= 1)
		throw NoSpanMiMang();
	size_t span = longestSpan();

	for (std::vector<int>::iterator itr = this->_arr.begin(); itr != this->_arr.end() - 1; itr++)
	{
		if (static_cast<size_t>(*(itr + 1) - *(itr)) < span)
			span = *(itr + 1) - *(itr);
	}
	return span;
}

size_t	Span::longestSpan(void)
{
	if (this->_arr.size() <= 1)
		throw NoSpanMiMang();
	return (*(this->_arr.end() - 1) - *(this->_arr.begin()));
}

const char* Span::ListFull::what() const throw()
{
	return "LIST FULL! unable to add number";
}

const char* Span::NoSpace::what() const throw()
{
	return "No space for an array this big amigo🇲🇽";
}

const char* Span::NoSpanMiMang::what() const throw()
{
	return "Unable to find span, list too short";
}
