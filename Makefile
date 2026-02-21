NAME = libft.a

PROG = program
CC = gcc
CFLAGS = -Wall -Wextra -Werror 		

SRC = function2.c function3.c function.c
OBJ = $(SRC:.c=.o)

all: $(NAME) $(PROG)

$(NAME):$(OBJ)
	ar rcs $(NAME) $(OBJ)

$(PROG):main.c $(NAME)
	$(CC) $(CFLAGS) main.c $(NAME) -o $(PROG)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

run: all
	./$(PROG)

clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME) $(PROG)