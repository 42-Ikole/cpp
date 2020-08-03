NAME = phonebook

SRC = phonebook.cpp

FLAGS = -Wall -Wextra -Werror

.PHONY: clean fclean

all: $(NAME)

$(NAME): $(SRC)
	clang++ $(SRC) -o $(NAME)

%.o: %.cpp
	@printf "\e[0;34mCompiling $<\n\e[0;35m"
	@clang++ $(FLAGS) -c $< -o $@

test: all
	@printf "\e[0;0m"
	./phonebook

re: fclean all

fclean: clean
	@rm -f $(NAME)
