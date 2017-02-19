# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: spalmaro <spalmaro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/16 15:33:41 by spalmaro          #+#    #+#              #
#    Updated: 2017/02/19 17:30:22 by spalmaro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

C_FILES = ft_parse.c ft_drawmap.c main.c

SRC_PATH = src/

OBJ_NAME = $(C_FILES:.c=.o)

HEADER_FLAG = -I includes/

MLX_FL = -lmlx -framework OpenGL -framework Appkit

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
	@$(CC) $(addprefix $(SRC_PATH), $(C_FILES)) $(LIB) $(MLIBX) -o $(NAME) $(MLX_FL)

gcc:
	@$(CC) $(addprefix $(SRC_PATH), $(C_FILES)) $(LIB) $(MLIBX) -o $(NAME) $(MLX_FL)

clean:
	make clean $(LIBFT)
	make clean $(MINILIBX)

fclean: clean
	make fclean $(LIBFT)
	@rm -f $(NAME)

re: fclean all
