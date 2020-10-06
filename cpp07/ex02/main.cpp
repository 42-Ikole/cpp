
#include "Array.hpp"
#include <iostream>

class   Awesome 
{
public:
	Awesome(){} //added this to make array possible
	Awesome( int n ) : _n( n ) {}
	bool	operator==( Awesome const & rhs ) const { return (this->_n == rhs._n); }
	bool	operator!=( Awesome const & rhs ) const { return (this->_n != rhs._n); }
	bool	operator>( Awesome const & rhs ) const { return (this->_n > rhs._n); }
	bool	operator<( Awesome const & rhs ) const { return (this->_n < rhs._n); }
	bool	operator>=( Awesome const & rhs ) const { return (this->_n >= rhs._n); }
	bool	operator<=( Awesome const & rhs ) const { return (this->_n <= rhs._n); }
	void	print_n(void) { std::cout << this->_n << std::endl; }
	int		get_n(void) const { return (this->_n); }
private:
	int _n;
};

std::ostream &operator<<(std::ostream &o, const Awesome &a)
{
	o << a.get_n();
	return (o);
}

void	test(void)
{
	Array<int> arr0(21);
	for (unsigned int i = 0; i < arr0.size(); i++)
		arr0[i] = i;
	std::cout << "int array test" << std::endl;
	for (unsigned int i = 0; i < arr0.size(); i++)
		std::cout << "[" << i << "] " << arr0[i] << std::endl;
	std::cout << std::endl << "copy constructor test" << std::endl;
	Array<int> arr1(arr0);
	for (unsigned int i = 0; i < arr1.size(); i++)
		std::cout << "[" << i << "] " << arr1[i] << std::endl;
	
	Array<Awesome> arrA(5);
	for (unsigned int i = 0; i < arrA.size(); i++)
		arrA[i] = Awesome(i);
	std::cout << std::endl << "Awesome array test" << std::endl;
	for (unsigned int i = 0; i < arrA.size(); i++)
		std::cout << "[" << i << "] " << arrA[i] << std::endl;
}

int		main()
{
	test();
	system("leaks a.out");
	return (0);
}
