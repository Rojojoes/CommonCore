# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rogde-so <rogde-so@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/11 19:04:10 by rogde-so          #+#    #+#              #
#    Updated: 2025/07/11 19:22:04 by rogde-so         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -I./libft

NAME = pipex
LIB_DIR = libft
LIB_A = $(LIB_DIR)/libft.a

SRC = pipex.c \
		pipex_pipe.c \
		pipex_free.c \
		pipex_split.c

OBJ = $(SRC:.c=.o)

all: $(LIB_A) $(NAME)

$(LIB_A):
	$(MAKE) -C $(LIB_DIR)

$(NAME): $(OBJ) $(LIB_A)
	$(CC) $(CFLAGS) $(OBJ) $(LIB_A) -o $(NAME)

%.o: %.c pipex.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C $(LIB_DIR) clean
	rm -f $(OBJ)

fclean: clean
	$(MAKE) -C $(LIB_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
