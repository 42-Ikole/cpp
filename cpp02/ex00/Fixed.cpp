
#include <iostream>
#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called\n";
	point = 0;
}

Fixed::Fixed(const Fixed &tbc)
{
    std::cout << "Copy constructor called\n";
	point = tbc.getRawBits();
}

Fixed::~Fixed()
{
     std::cout << "Destructor called\n";
}

int		Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits called\n";
    return point;
}

void	Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits called\n";
    point = raw;
}

void	Fixed::operator = (const Fixed &tbc)
{
    std::cout << "assignation operator called\n";
    point = tbc.getRawBits();
}
