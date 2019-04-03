CC = gcc
NAME = test_gnl
FLAG = -Wall -Wextra -Werror
SRC = sandbox.c
OBJ = $(SRC:.c=.o)

$(NAME):
	make -C libft/ fclean && make -C libft/
	clang $(FLAG) -I libft/ -c $(SRC)
	clang -o $(NAME) $(OBJ) -I libft/ -L libft/ -lft

all: $(NAME)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re:	fclean all

%.o: %.c
	$(CC) $(FLAG) -c $< -o $@

.PHONY: all clean fclean re