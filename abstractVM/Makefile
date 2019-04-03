NAME = avm
CC = clang++
CFLAGS = -Wall -Wextra -Werror -std=c++11
SRC = main.cpp Operand.cpp Exceptions.cpp ops.cpp
OBJ = $(SRC:.cpp=.o)

$(NAME):
	@$(CC) $(CFLAGS) $(SRC) -o $(NAME)

all: $(NAME)

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re:	fclean all
