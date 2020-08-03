
#ifndef FIXED_H
# define FIXED_H

class Fixed
{
private:
    int 				point;
    static const int	fraction = 8;
public:
    Fixed();
	Fixed(const Fixed &tbc);
    ~Fixed();
	void	operator = (const Fixed &tbc);
	int		getRawBits( void ) const;
	void	setRawBits(int const raw);
};

#endif
