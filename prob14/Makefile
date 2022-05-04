##
## PERSONAL PROJECT, 2019
## collatz
## File description:
## Makefile
##

SRC	=	main_collatz.c

OBJ	=	$(SRC:.c=.o)

LIB	=	../libmy.a

CC	=	@gcc

CFLAGS	=	-Wall -Werror -Wextra --pedantic

NAME	=	collatz

.PHONY: clean fclean re collatz

all: $(NAME)

$(NAME): $(OBJ)
	@echo Compiling \'$(NAME)\'
	$(CC) -o $(NAME) $(OBJ) $(LIB)
	@echo \'$(NAME)\' compiled successfully

clean:
	@rm -rf $(OBJ)
	@echo Cleaned .o for \'$(NAME)\'

fclean:	clean
	@rm -rf $(NAME)
	@echo Cleaned \'$(NAME)\'

re: fclean all
