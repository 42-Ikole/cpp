
#include "Convert.hpp"
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <string>

/////////////
// Helpers //
/////////////

	static bool				isPseudoLiteral(const std::string& input)
	{
		return (input == "nan"   || input == "nanf" ||
				input == "inf"   || input == "inff" ||
				input == "-inf"  || input == "+inf" ||
				input == "-inff" || input == "+inff");
	}

	static bool				isCharLiteral(const std::string& input)
	{
		if (input.size() != 1)
			return false;
		// return true if it is not a number
		return (input[0] < '0' || input[0] > '9');
	}

	static Convert::type		isNumericLiteral(const std::string& input)
	{
		size_t i = 0;

		// skip whitespace
		while ((input[i] >= 9 && input[i] <= 13) || input[i] == ' ')
			++i;
		// skip sign
		if (input[i] == '-' || input[i] == '+')
			++i;
		// skip all numbers
		while (input[i] && input[i] >= '0' && input[i] <= '9')
			++i;
		// it is an INT if end of string is reached
		if (i == input.length())
			return Convert::INT;
		// skip the decimal point
		if (input[i] == '.')
			++i;
		// skip all numbers after decimal point
		while (input[i] && input[i] >= '0' && input[i] <= '9')
			++i; 
		if (i == input.length())
			return Convert::DOUBLE;
		// it is a float
		if (input[i] == 'f' && i + 1 == input.length())
			return Convert::FLOAT;
		// unkown type
		else
			return Convert::UNKNOWN;
	}

	static Convert::type	getType(const std::string& input)
	{
		if (isPseudoLiteral(input) == true)
			return Convert::PSEUDO_LITERAL;
		if (isCharLiteral(input) == true)
			return Convert::CHAR;
		return (isNumericLiteral(input));
	}

	static size_t			getPrecisePrecision(const std::string& input)
	{
		size_t pos = input.find_first_of('.');
		if (pos == std::string::npos)
			return (1);
		return (input.length() - (pos + ((input[input.length() - 1] == 'f') ? 2 : 1)));
	}

/////////////
// CoPlIeN //
/////////////

	Convert::Convert(const std::string& input)
		: _raw(input)
	{
		this->_type			= getType(input);
		this->_precision	= getPrecisePrecision(input);

		switch (_type)
		{
			case CHAR:
				_data.c = input[0]; break;
			case INT:
				_data.i = std::stoi(input); break;
			case FLOAT:
				_data.f = std::stof(input); break;
			case DOUBLE:
				_data.d = std::stod(input); break;
			case PSEUDO_LITERAL:
				_data.d = std::stod(input); break;
			default:
				throw UnknownType();
		}
	}

	Convert::Convert(const Convert& x)
		: _raw(x._raw)
	{
		*this = x;
	}

	Convert::~Convert()
	{
	}

	Convert& Convert::operator = (const Convert& x)
	{
		this->_data			= x._data;
		this->_precision	= x._precision;
		this->_type			= x._type;
		return *(this);
	}

////////////////
// Converters //
////////////////

	void	Convert::printChar(std::ostream& o) const
	{
		o << "char: ";
		try {
			char c = convertToType<char>();

			if (std::isprint(c) == false)
				o << "Non displayable";
			else
				o << '\'' << c << '\'';
		} catch (const Impossible& e) {
			o << e.what();
		}
		o << "\n";
	}

	void	Convert::printInt(std::ostream& o) const
	{
		o << "int: ";
		try {
			o << convertToType<int>();
		} catch (const Impossible& e) {
			o << e.what();
		}
		o << "\n";
	}
	
	void	Convert::printFloat(std::ostream& o) const
	{
		o << "float: ";
		if (_type == PSEUDO_LITERAL)
			o << _raw << ((_raw[_raw.length() - 1] == 'f') ? "" : "f");
		else {
			try {
				o << convertToType<float>() << 'f';
			} catch (const Impossible& e) {
				o << e.what();
			}
		}
		o << "\n";
	}

	void	Convert::printDouble(std::ostream& o) const
	{
		o << "double: ";
		if (_type == PSEUDO_LITERAL)
			o << _raw;
		else {
			try {
				o << convertToType<double>();
			} catch (const Impossible& e) {
				o << e.what();
			}
		}
		o << "\n";
	}

/////////////
// Getters //
/////////////

	size_t 	Convert::getPrecision() const
	{
		return _precision;
	}

///////////////////////
// Operator overload //
///////////////////////

	template<typename T>
		static void	printConversion(std::ostream& o, const std::string& conversion, const Convert& c, T(Convert::*convertFn)() const)
	{
		try {
			o << conversion << ": " << (c.*convertFn)() << "\n";
		} catch (const std::exception& e) {
			o << e.what() << "\n";
		}
	}

	std::ostream&	operator << (std::ostream& o, const Convert& c)
	{
		o << std::setprecision(c.getPrecision()) << std::fixed;

		c.printChar(o);
		c.printInt(o);
		c.printFloat(o);
		c.printDouble(o);

		return o;
	}
