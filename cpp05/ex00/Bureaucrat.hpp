
#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>

class Bureaucrat
{
	private:
		int			grade;
		std::string name;
		Bureaucrat();
	public:
		Bureaucrat(const std::string name, const int grade);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat &copy);
		Bureaucrat & operator = (const Bureaucrat &s);
		std::string getName();
		int			getGrade();
		void		incGrade();
		void		decGrade();
};


#endif
