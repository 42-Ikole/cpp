#include <iostream>

template<typename T>
void	iter(T *arr, int length, void(*f)(T&))
{
	for (int i = 0; i < length; i++)
		f(arr[i]);
}

class   Awesome 
{
public:
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

void	multiply(int &i)
{
	i <<= 2;
}

void	prnt(Awesome &a)
{
	std::cout << a.get_n() << " ";
}

void	addchar(std::string &s)
{
	s += " ";
}

void	test(void)
{
	std::cout << "\ntest with int array" << std::endl;
	int	arr0[10] = {1,2,3,4,5,6,7,8,9,10};
	for (int i = 0; i < 10; i++)
		std::cout << arr0[i] << " ";
	std::cout << std::endl;
	iter(arr0, 10, multiply);
	for (int i = 0; i < 10; i++)
		std::cout << arr0[i] << " ";
	std::cout << std::endl;

	std::cout << "\ntest with string array" << std::endl;
	std::string arr2[6] = {"hey","I","am","very","fluffy",":)"};
	for (int i = 0; i < 6; i++)
		std::cout << arr2[i];
	std::cout << std::endl;
	iter(arr2, 6, addchar);
	for (int i = 0; i < 6; i++)
		std::cout << arr2[i];
	std::cout << std::endl;

	std::cout << "\ntest with awesome array" << std::endl;
	Awesome	arr1[10] = {Awesome(1),Awesome(2),Awesome(3),Awesome(4),Awesome(5),Awesome(6),Awesome(7),Awesome(8),Awesome(9),Awesome(10)};
	iter(arr1, 10, prnt);
	std::cout << std::endl;
}

int		main(int ac, char **av)
{
	test();
	std::string	s = av[0];
	s = "leaks " + s.erase(0,2);
	if (ac > 1 && !strcmp(av[1],"leaks"))
		system(s.c_str());
	else
	{
		s += " >> leaks.txt";
		system(s.c_str());
		system("grep \"total leaked bytes\" leaks.txt");
		system("rm leaks.txt");
	}
	return (0);
}

