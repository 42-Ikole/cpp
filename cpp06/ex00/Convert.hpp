#ifndef CONVERT_HPP
# define CONVERT_HPP

# include <string>
# include <exception>

union u_data {
	char	c;
	int		i;
	float	f;
	double	d;
};

class Convert
{
	///////////
	// Enums //
	///////////
	public:

		typedef enum e_type {
			CHAR,
			INT,
			FLOAT,
			DOUBLE,
			PSEUDO_LITERAL,
			UNKNOWN
		} type;

	//////////////////
	// Member types //
	//////////////////
	private:

		const std::string&	_raw;
		size_t				_precision;
		u_data				_data;
		e_type				_type;

	/////////////
	// CoPlIeN //
	/////////////
	private:

		Convert();

	public:

		Convert(const std::string& input);
		Convert(const Convert& x);
		virtual ~Convert();
		Convert& operator = (const Convert& x);

	/////////////////////
	// Private methods //
	/////////////////////
	private:

		template<typename T>
			T convertToType() const
		{
			switch (_type)
			{
				case CHAR:
					return static_cast<T>(_data.c);
				case INT:
					return static_cast<T>(_data.i);
				case FLOAT:
					return static_cast<T>(_data.f);
				case DOUBLE:
					return static_cast<T>(_data.d);
				default:
					throw Impossible();
			}
		}
	
	////////////////
	// Converters //
	////////////////
	public:

		void	printChar(std::ostream& o) const;
		void	printInt(std::ostream& o) const;
		void	printFloat(std::ostream& o) const;
		void	printDouble(std::ostream& o) const;

	/////////////
	// Getters //
	/////////////
	public:

		size_t	getPrecision() const;

	////////////////
	// Exceptions //
	////////////////
	public:

		struct UnknownType : public std::exception {
			const char* what() const throw() {
				return "unknown type";
			}
		};

		struct Impossible : public std::exception {
			const char* what() const throw() {
				return "impossible";
			}
		};

}; /* end of class */


std::ostream&	operator << (std::ostream& o, const Convert& c);

#endif
