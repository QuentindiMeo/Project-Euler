##
## PERSONAL PROJECT, 2019
## smallest
## File description:
## Makefile
##

SRC	=	main_smallest.c	\

OBJ	=	$(SRC:.c=.o)

INCLUDE	=	include/

CC	=	@gcc

CFLAGS	=	-Wall -Werror -Wextra --pedantic

NAME	=	smallest

CPPFLAGS	=	-I $(INCLUDE)

all: $(NAME)

$(NAME): $(OBJ)
	@echo Compiling \'$(NAME)\'
	$(CC) -o $(NAME) $(OBJ) $(CPPFLAGS)
	@echo \'$(NAME)\' compiled successfully

clean:
	@rm -rf $(OBJ)
	@echo Cleaned .o for \'$(NAME)\'

fclean:	clean
	@rm -rf $(NAME)
	@echo Cleaned \'$(NAME)\'

re: fclean all

.PHONY: clean fclean re smallest
