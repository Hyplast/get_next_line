# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: severi <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/13 16:25:04 by severi            #+#    #+#              #
#    Updated: 2022/01/08 02:29:45 by severi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = test_gnl

LIB = libft

SRC = get_next_line.c main.c

INC = libft.h get_next_line.h

INCLIB = libft/includes

LIBDIR = libft/

OBJ  = $(SRC:.c=.o)

CC = clang
CFLAGS = -ggdb -fsanitize=address -Wall -Wextra -Werror -Wconversion
#CFLAGS = -g -Wall -Wextra -Werror -Wconversion

all: $(NAME)

$(NAME): $(LIB)
	$(CC) $(CFLAGS) -I $(INCLIB) -o get_next_line.o -c get_next_line.c
	$(CC) $(CFLAGS) -I $(INCLIB) -o main.o -c main.c
	$(CC) -ggdb -fsanitize=address -static-libsan -o $(NAME) $(OBJ) -I $(INCLIB) -L $(LIBDIR) -lft

$(LIB):
	make -C $(LIBDIR) fclean && make -C $(LIBDIR)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRC)
	gcc -nostartfiles -shared -o libft.so $(OBJ)

.PHONY: clean fclean all
