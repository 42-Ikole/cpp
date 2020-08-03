NAME = replace

SRC = replace.cpp

FLAGS = -Wall -Wextra -Werror

.PHONY: clean fclean

all: $(NAME)

$(NAME): $(SRC)
	clang++ $(SRC) -o $(NAME)

%.o: %.c
	@printf "\e[0;34mCompiling $<\n\e[0;35m"
	@gcc $(FLAGS) -c $< -o $@

test: all
	@printf "\e[0;0m"
	./replace test hoi nice

re: fclean all

clean:
	@rm -f test.replace

fclean: clean
	@rm -f $(NAME)
