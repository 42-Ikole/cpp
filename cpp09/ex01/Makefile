
NAME = RPN

SRCS = src/main.cpp src/ReversePolishNotationCalculator.cpp

$(NAME): $(SRCS)
	clang++ -Wall -Wextra -Werror -g $(SRCS) -o $(NAME)

all: $(NAME)

re: fclean all

fclean:
	@rm -rf $(NAME)
