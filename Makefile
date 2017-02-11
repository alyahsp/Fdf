NAME = fdf

C_FILES = ft_parse.c main.c

SRC_PATH = src/

OBJ_NAME = $(C_FILES:.c=.o)

HEADER_FLAG = -I includes/

LIB = libft/libft.a

MLIBX = minilibx_macos/libmlx.a

LIBFT = -C libft/

MINILIBX = -C minilibx_macos/

CC = gcc

CFLAGS = -Wall -Wextra -Werror

.PHONY : all clean fclean re

all: $(NAME)

$(NAME):
	make $(LIBFT)
	make $(MINILIBX)
	@$(CC) $(C_FILES) $(LIB) $(MLIBX)-o $(NAME)

clean:
	make clean $(LIBFT)

fclean:
	make fclean $(LIBFT)
	make fclean $(MINILIBX)
	@rm -f $(NAME)

re: fclean all
