NAME = replace

SRC = replace.cpp

FLAGS = -Wall -Wextra -Werror -std=c++98

.PHONY: clean fclean

all: $(NAME)

$(NAME): $(SRC)
	clang++ $(FLAGS) $(SRC) -o $(NAME)

%.o: %.c
	@printf "\e[0;34mCompiling $<\n\e[0;35m"
	@clang++ $(FLAGS) -c $< -o $@

test: all
	@printf "\e[0;0m"
	./replace test hoi nice

re: fclean all

clean:
	@rm -f test.replace

fclean: clean
	@rm -f $(NAME)
