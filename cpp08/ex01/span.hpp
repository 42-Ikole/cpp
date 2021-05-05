
#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
#include <exception>

class Span
{
	private:
		unsigned int		_N;
		std::vector<int>	_arr;
		Span();
	public:
		Span(unsigned int N);
		Span(const Span &tbc);
		virtual ~Span();
		Span & operator = (const Span &tba);
		void	addNumber(const int nb);
		void	addNumber(const std::vector<int>::iterator, const std::vector<int>::iterator);
		size_t	shortestSpan(void);
		size_t	longestSpan(void);

	class ListFull : public std::exception
	{
		public:
			const char* what() const throw();
	};

	class NoSpace : public std::exception
	{
		public:
			const char* what() const throw();
	};

	class NoSpanMiMang : public std::exception
	{
		public:
			const char* what() const throw();
	};
};

#endif
