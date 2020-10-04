
NAME = convert

SRCS = main.cpp PrintInput.cpp

all: $(NAME)
	clang++ -Wall -Wextra -Werror $(SRCS) -o $(NAME)

test: all
	./convert 65

re: fclean all

fclean:
	@rm -rf $(NAME)