
#include <iostream>
#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called\n";
	_point = 0;
}

Fixed::Fixed(const Fixed &tbc)
{
    std::cout << "Copy constructor called\n";
	_point = tbc.getRawBits();
}

Fixed::~Fixed()
{
     std::cout << "Destructor called\n";
}

int		Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits called\n";
    return _point;
}

void	Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits called\n";
    _point = raw;
}

void	Fixed::operator = (const Fixed &tbc)
{
    std::cout << "assignation operator called\n";
    _point = tbc.getRawBits();
}
