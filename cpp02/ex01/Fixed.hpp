
#ifndef FIXED_H
# define FIXED_H

#include <iostream>

class Fixed
{
private:
    int 				_point;
    static const int	_fraction = 8;
public:
    Fixed();
    Fixed(int nbr);
    Fixed(float nbr);
	Fixed(const Fixed &tbc);
    ~Fixed();
	void	operator = (const Fixed &tbc);
	int		getRawBits( void ) const;
	void	setRawBits(int const raw);
    float   toFloat( void ) const;
    int     toInt( void ) const;
};

std::ostream   &operator << (std::ostream &out, const Fixed &tbp);

#endif
