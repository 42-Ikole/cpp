
NAME = btc

SRCS = src/main.cpp src/BitcoinExchange.cpp src/ParseFile.cpp src/Utility.cpp

$(NAME): $(SRCS)
	clang++ -Wall -Wextra -Werror -std=c++20 $(SRCS) -o $(NAME)

all: $(NAME)

re: fclean all

fclean:
	@rm -rf $(NAME)
