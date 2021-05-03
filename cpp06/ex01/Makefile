
NAME = serialize

SRCS = main.cpp Serialization.cpp

$(NAME): $(SRCS)
	clang++ -Wall -Wextra -Werror $(SRCS) -o $(NAME)

all: $(NAME)

re: fclean all

fclean:
	@rm -rf $(NAME)