
NAME = PmergeMe

SRCS = src/main.cpp

$(NAME): $(SRCS)
	$(CXX) -Wall -Wextra -Werror -std=c++23 $(SRCS) -o $(NAME)

all: $(NAME)

re: fclean all

fclean:
	@rm -rf $(NAME)
