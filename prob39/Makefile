##
## PERSONAL PROJECT, 2020
## pythagoras
## File description:
## Makefile 
##

SRC	=	main_pythagoras.c	\

OBJ	=	$(SRC:.c=.o)

CC	=	@gcc -lm

LIB     =       ../libmy.a

CFLAGS	=	-Wall -Werror -Wextra --pedantic

NAME	=	pythagoras

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

.PHONY: clean fclean re pythagoras
