
NAME	=	ex03

SRC		=	main.cpp \
			Bureaucrat.cpp \
			AForm.cpp \
			PresidentialPardonForm.cpp \
			RobotomyRequestForm.cpp \
			ShrubberyCreationForm.cpp \
			Intern.cpp

INCL	=	-I.

FLAGS	=	-Wall -Wextra -Werror -pedantic -std=c++98

CC		=	clang++

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(FLAGS) $(SRC) $(INCL) -o $(NAME)

re: fclean all

clean:
	$(RM) *_shrubbery

fclean: clean
	$(RM) $(NAME)
