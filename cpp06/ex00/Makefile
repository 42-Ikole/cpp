
SRCS = main.cpp PrintInput.cpp

all:
	clang++ $(SRCS) -o convert

test: all
	./convert 65

re: fclean all

fclean:
	@rm -rf convert