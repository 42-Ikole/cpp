
#include "Convert.hpp"
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <limits>

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

	static Convert::type		getNumericType(const std::string& input)
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
		return (getNumericType(input));
	}

	static size_t			getPrecisePrecision(const std::string& input)
	{
		size_t pos = input.find_first_of('.');
		if (pos == std::string::npos || pos + 1 == input.length())
			return (1);
		pos += 1;
		pos += (input[input.length() - 1] == 'f');
		if (pos == input.length())
			return (1);
		return (input.length() - pos);
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
		this->validateSize<char>();
		char c = convertToType<char>();

		if (std::isprint(c) == false)
			throw NonDisplayable();
		o << '\'' << c << '\'';
	}

	void	Convert::printInt(std::ostream& o) const
	{
		this->validateSize<int>();
		o << convertToType<int>();
	}
	
	void	Convert::printFloat(std::ostream& o) const
	{
		this->validateSize<float>();
		if (_type == PSEUDO_LITERAL)
			o << _raw << ((_raw[_raw.length() - 1] == 'f') ? "" : "f");
		else
			o << convertToType<float>() << 'f';
	}

	void	Convert::printDouble(std::ostream& o) const
	{
		if (_type == PSEUDO_LITERAL)
			o << _raw;
		else
			o << convertToType<double>();
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

	static void	printConversion(std::ostream& o, const std::string& conversion, const Convert& c, void(Convert::*convertFn)(std::ostream&) const)
	{
		try {
			o << conversion << ": ";
			(c.*convertFn)(o);
			o << "\n";
		} catch (const std::exception& e) {
			o << e.what() << "\n";
		}
	}

	std::ostream&	operator << (std::ostream& o, const Convert& c)
	{
		o << std::setprecision(c.getPrecision()) << std::fixed;

		printConversion(o, "char", c, &Convert::printChar);
		printConversion(o, "int", c, &Convert::printInt);
		printConversion(o, "float", c, &Convert::printFloat);
		printConversion(o, "double", c, &Convert::printDouble);

		return o;
	}
