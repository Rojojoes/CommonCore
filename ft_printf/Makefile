# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rogde-so <rogde-so@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/18 15:52:53 by rogde-so          #+#    #+#              #
#    Updated: 2025/05/08 12:43:00 by rogde-so         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g \
		-I. \
		-I./libft

LIB_DIR = libft
LIB_A = $(LIB_DIR)/libft.a
NAME = libftprintf.a

PRINT_SRC =	ft_printf.c ft_print_utils.c ft_print_utils_hexa.c 
MAIN_SRC = printfmain.c

OBJ = $(PRINT_SRC:.c=.o) 
MAIN_OBJ = $(MAIN_SRC:.c=.o)

EXE = printme

.PHONY: all libft libftprintf exec clean fclean re

all: libft libftprintf exec

libft:
	@make -C $(LIB_DIR)

libftprintf: $(OBJ) $(LIB_A)
		@cp $(LIB_A) $(NAME)
		@ar rcs $(NAME) $(OBJ)

exec: $(NAME) .exec

.exec: $(MAIN_OBJ) $(OBJ)
	@$(CC) $(CFLAGS) $(MAIN_OBJ) $(NAME) -o $(EXE)
	@touch .exec

%.o: %.c ft_printf.h libft/libft.h
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make -C $(LIB_DIR) clean
	@rm -f $(OBJ) $(MAIN_OBJ) .exec

fclean: clean
	@make -C $(LIB_DIR) fclean
	@rm -f $(NAME) $(EXE)

re: fclean all

