
#include <iostream>
#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed()
{
    // std::cout << "Default constructor called\n";
    point = 0;
}

Fixed::Fixed(int nbr)
{
    // std::cout << "Int constructor called\n";
	point = nbr << fraction;
}

Fixed::Fixed(float nbr)
{
    // std::cout << "Float constructor called\n";
	point = (int)roundf(nbr * (1 << fraction));
}

Fixed::Fixed(const Fixed &tbc)
{
    // std::cout << "Copy constructor called\n";
	*this = tbc;
}

Fixed::~Fixed()
{
    //  std::cout << "Destructor called\n";
}

int		Fixed::getRawBits( void ) const
{
    // std::cout << "getRawBits called\n";
    return point;
}

void	Fixed::setRawBits(int const raw)
{
    // std::cout << "setRawBits called\n";
    point = raw;
}

void	Fixed::operator = (const Fixed &tbc)
{
    // std::cout << "assignation operator called\n";
    point = tbc.getRawBits();
}


float   Fixed::toFloat( void ) const
{
    // std::cout << ((float)(1 << fraction)) << std::endl;
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


float			operator > (const Fixed &fpnbr1, const Fixed &fpnbr2)
{
    return (fpnbr1.getRawBits() > fpnbr2.getRawBits());
}

float			operator < (const Fixed &fpnbr1, const Fixed &fpnbr2)
{
    return (fpnbr1.getRawBits() < fpnbr2.getRawBits());
}

float			operator >= (const Fixed &fpnbr1, const Fixed &fpnbr2)
{
    return (fpnbr1.getRawBits() >= fpnbr2.getRawBits());
}

float			operator <= (const Fixed &fpnbr1, const Fixed &fpnbr2)
{
    return (fpnbr1.getRawBits() <= fpnbr2.getRawBits());
}

float			operator == (const Fixed &fpnbr1, const Fixed &fpnbr2)
{
    return (fpnbr1.getRawBits() == fpnbr2.getRawBits());
}

float			operator != (const Fixed &fpnbr1, const Fixed &fpnbr2)
{
    return (fpnbr1.getRawBits() != fpnbr2.getRawBits());
}

float			operator + (const Fixed &fpnbr1, const Fixed &fpnbr2)
{
    return (fpnbr1.toFloat() + fpnbr2.toFloat());
}

float			operator - (const Fixed &fpnbr1, const Fixed &fpnbr2)
{
    return (fpnbr1.toFloat() - fpnbr2.toFloat());
}

float			operator * (const Fixed &fpnbr1, const Fixed &fpnbr2)
{
    return (fpnbr1.toFloat() * fpnbr2.toFloat());
}

float			operator / (const Fixed &fpnbr1, const Fixed &fpnbr2)
{
    return (fpnbr1.toFloat() / fpnbr2.toFloat());
}

float			Fixed::operator ++ ()
{
    ++point;
    return (toFloat());
}

float			Fixed::operator ++ (int)
{
    float tmp;
    tmp = toFloat();
    point++;
    return (tmp);
}

float			Fixed::operator -- ()
{
    point++;
    return (toFloat());
}

float			Fixed::operator -- (int)
{
    float tmp;
    tmp = toFloat();
    point--;
    return (tmp);
}

Fixed			min(Fixed fpnbr1, Fixed fpnbr2)
{
    return ((fpnbr1 > fpnbr2) ? fpnbr2 : fpnbr1);
}

const Fixed&	Fixed::min(const Fixed &fpnbr1, const Fixed &fpnbr2)
{
    return ((fpnbr1 > fpnbr2) ? fpnbr2 : fpnbr1);
}

Fixed			max(Fixed fpnbr1, Fixed fpnbr2)
{
    return ((fpnbr1 > fpnbr2) ? fpnbr1 : fpnbr2);
}

const Fixed&	Fixed::max(const Fixed &fpnbr1, const Fixed &fpnbr2)
{
    return ((fpnbr1 > fpnbr2) ? fpnbr1 : fpnbr2);
}

