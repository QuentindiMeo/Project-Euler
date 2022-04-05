##
## PERSONAL PROJECT, 2022
## recurring
## File description:
## Makefile 
##

SRC	=	main_recurring.c\

OBJ	=	$(SRC:.c=.o)

INCLUDE	=	include/

CC	=	@gcc

LIB     =       ../libmy.a

CFLAGS	=	-Wall -Werror -Wextra --pedantic -g3

NAME	=	recurring

CPPFLAGS	=	-I $(INCLUDE)

all: $(NAME)

$(NAME): $(OBJ)
	@echo Compiling \'$(NAME)\'
	$(CC) -o $(NAME) $(OBJ) $(LIB) $(CPPFLAGS)
	@echo \'$(NAME)\' compiled successfully

clean:
	@rm -rf $(OBJ)
	@echo Cleaned .o for \'$(NAME)\'

fclean:	clean
	@rm -rf $(NAME)
	@echo Cleaned \'$(NAME)\'

re: fclean all

.PHONY: clean fclean re 
