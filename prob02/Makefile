##
## PERSONAL PROJECT, 2019
## fibonacci
## File description:
## Makefile
##

SRC	=	main_fib.c	\

OBJ	=	$(SRC:.c=.o)

CC	=	@gcc

LIB     =       ../libmy.a

CFLAGS	=	-Wall -Werror -Wextra --pedantic

NAME	=	fib

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

.PHONY: clean fclean re fib
