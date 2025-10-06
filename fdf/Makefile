# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rogde-so <rogde-so@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/31 18:45:53 by rogde-so          #+#    #+#              #
#    Updated: 2025/08/31 19:15:46 by rogde-so         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = fdf
LIB_DIR = libft
MLX_DIR = minilibx-linux
LIB_A = $(LIB_DIR)/libft.a
MLX_A = $(MLX_DIR)/libmlx.a

SRC = fdf.c \
		fdf_init.c \
		fdf_draw.c \
		fdf_matrix.c \
		fdf_draw_lines.c \
		fdf_free_memory.c \
		fdf_hooks_close.c

OBJ = $(SRC:.c=.o)

all: $(LIB_A) $(NAME)

$(LIB_A):
		$(MAKE) -C $(LIB_DIR)

$(MLX_A):
		$(MAKE) -C $(MLX_DIR)

$(NAME): $(OBJ) $(LIB_A) $(MLX_A)
		$(CC) $(CFLAGS) $(OBJ) $(LIB_A) $(MLX_A) -lm -lXext -lX11 -o $(NAME)

%.o: %.c fdf.h
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		$(MAKE) -C $(LIB_DIR) clean
		rm -f $(OBJ)

fclean: clean
		$(MAKE) -C $(LIB_DIR) fclean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re