
#ifndef PRINTINPUT_HPP
# define PRINTINPUT_HPP

class PrintInput
{
	private:
		char	*p_input;
		int		p_nb;
		double	p_dnb;
		PrintInput();
		void	printChar() const;
		void	printInt() const;
		void	printFloat() const;
		void	printDouble() const;
		bool	isLiteral() const;
		bool	isValidInput() const;
	public:
		PrintInput(char *str);
		~PrintInput();
		PrintInput(const PrintInput &copy);
		PrintInput & operator = (const PrintInput &s);
		void	PrintNumbers() const;
};

#endif
