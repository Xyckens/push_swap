# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fvieira <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/06 12:23:12 by fvieira           #+#    #+#              #
#    Updated: 2023/01/06 12:23:14 by fvieira          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc

FLAGS = -Wall -Werror -Wextra -I.

LIBFT = ./libft/libft.a

SRC = checker.c \
	main.c \
	ops1.c \
	ops2.c \
	ops3.c \
	put_right_place.c \
	sorting.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		$(MAKE) --no-print-directory -C ./libft
		$(CC) $(FLAGS) $(OBJ) $(LIBFT) -o $(NAME)

clean:
		$(MAKE) clean -C ./libft
		rm -f $(OBJ)
		echo "OBJ deleted"

fclean: clean
		$(MAKE) fclean -C ./libft
		rm -f $(NAME)
		echo "$(NAME) deleted"

re: fclean all

.SILENT:

.PHONY: all, clean, fclean, re
