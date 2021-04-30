
NAME = convert

SRCS = main.cpp PrintInput.cpp

$(NAME): $(SRCS)
	clang++ -Wall -Wextra -Werror $(SRCS) -o $(NAME)

all: $(NAMe)

test: all
	./convert 65

re: fclean all

fclean:
	@rm -rf $(NAME)
