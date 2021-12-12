
NAME = test_gnl

LIB = libft

SRC = get_next_line.c main.c

INC = libft.h get_next_line.h

OBJ  = $(SRC:.c=.o)

CC = clang

CFLAGS =  -Wall -Wextra -Werror -I libft/ 

.PHONY: clean fclean all

all: $(NAME)

$(NAME): $(LIB)
	@$(CC) $(CFLAGS) -o get_next_line.o -c get_next_line.c
	@$(CC) $(CFLAGS) -o main.o -c main.c
	@$(CC) -o $(NAME) main.o get_next_line.o -I libft/ -L libft/ -lft

$(LIB):
	@make -C libft/ fclean && make -C libft/

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRC)
	gcc -nostartfiles -shared -o libft.so $(OBJ)

