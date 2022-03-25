
NAME	=	convert

SRC		=	main.cpp \
			Convert.cpp

INCL	=	-I.

FLAGS	=	-Wall -Wextra -Werror -pedantic -std=c++98

CC		=	clang++

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(FLAGS) $(SRC) $(INCL) -o $(NAME)

re: fclean all

fclean:
	$(RM) $(NAME)
