
#include <iostream>
#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called\n";
    point = 0;
}

Fixed::Fixed(int nbr)
{
    std::cout << "Int constructor called\n";
	point = nbr << fraction;
}

Fixed::Fixed(float nbr)
{
    std::cout << "Float constructor called\n";
	point = (int)roundf(nbr * (1 << fraction));
}

Fixed::Fixed(const Fixed &tbc)
{
    std::cout << "Copy constructor called\n";
	*this = tbc;
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


float   Fixed::toFloat( void ) const
{
    // std::cout << ((float)(1 << fraction)) << std::endl
    return ((float)(point) / (1 << fraction));
}

std::ostream   &operator << (std::ostream &out, const Fixed &tbp)
{
    out << tbp.toFloat();
    return out;
}

int     Fixed::toInt( void ) const
{
    return (point >> fraction);
}
