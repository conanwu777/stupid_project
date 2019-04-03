NAME = ft_ls

CC = @gcc
CFLAGS = -Wall -Wextra -Werror
SRC = ft_ls.c input.c output.c support.c
OBJ = $(SRC1:.c=.o)
FT_LNK = -L ./libft -lft

all:
	@make -C libft
	@echo "Making ft_ls"
	$(CC) $(CFLAGS) $(FT_LNK) $(SRC) -o $(NAME)

clean:
	rm -f $(OBJ)
	make clean -C libft

fclean: clean
	rm -f $(NAME)
	make fclean -C libft

re:	fclean all
