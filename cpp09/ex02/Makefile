
NAME = PmergeMe

SRCS = src/main.cpp src/PmergeMe.cpp

$(NAME): $(SRCS)
	clang++ -Wall -Wextra -Werror -std=c++20 -g $(SRCS) -o $(NAME)

all: $(NAME)

re: fclean all

fclean:
	@rm -rf $(NAME)
