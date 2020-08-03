
#ifndef FIXED_H
# define FIXED_H

#include <iostream>

class Fixed
{
private:
    int 				point;
    static const int	fraction = 8;
public:
    Fixed();
    Fixed(int nbr);
    Fixed(float nbr);
	Fixed(const Fixed &tbc);
    ~Fixed();
	void	operator = (const Fixed &tbc);
	float	operator ++ ();
	float	operator ++ (int);
	float	operator -- ();
	float	operator -- (int);
	int		getRawBits( void ) const;
	void	setRawBits(int const raw);
    float   toFloat( void ) const;
    int     toInt( void ) const;
static const Fixed		&min(const Fixed &fpnbr1, const Fixed &fpnbr2);
static const Fixed		&max(const Fixed &fpnbr1, const Fixed &fpnbr2);
};

std::ostream	&operator << (std::ostream &out, const Fixed &tbp);
float			operator > (const Fixed &fpnbr1, const Fixed &fpnbr2);
float			operator < (const Fixed &fpnbr1, const Fixed &fpnbr2);
float			operator >= (const Fixed &fpnbr1, const Fixed &fpnbr2);
float			operator <= (const Fixed &fpnbr1, const Fixed &fpnbr2);
float			operator == (const Fixed &fpnbr1, const Fixed &fpnbr2);
float			operator != (const Fixed &fpnbr1, const Fixed &fpnbr2);
float			operator + (const Fixed &fpnbr1, const Fixed &fpnbr2);
float			operator - (const Fixed &fpnbr1, const Fixed &fpnbr2);
float			operator * (const Fixed &fpnbr1, const Fixed &fpnbr2);
float			operator / (const Fixed &fpnbr1, const Fixed &fpnbr2);
Fixed			min(Fixed fpnbr1, Fixed fpnbr2);
Fixed			max(Fixed fpnbr1, Fixed fpnbr2);

#endif
