
#include <iostream>
#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called\n";
    _point = 0;
}

Fixed::Fixed(int nbr)
{
    std::cout << "Int constructor called\n";
	_point = nbr << _fraction;
}

Fixed::Fixed(float nbr)
{
    std::cout << "Float constructor called\n";
	_point = (int)roundf(nbr * (1 << _fraction));
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

float   Fixed::toFloat( void ) const
{
    return ((float)(_point) / (1 << _fraction));
}

std::ostream   &operator << (std::ostream &out, const Fixed &tbp)
{
    out << tbp.toFloat();
    return out;
}

int     Fixed::toInt( void ) const
{
    return (_point >> _fraction);
}
