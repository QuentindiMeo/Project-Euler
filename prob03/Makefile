##
## PERSONAL PROJECT, 2019
## largest
## File description:
## Makefile
##

SRC	=	src/my_is_prime.c	\
		src/main_largest.c	\

OBJ	=	$(SRC:.c=.o)

INCLUDE	=	include/

CC	=	@gcc

CFLAGS	=	-Wall -Werror -Wextra --pedantic

NAME	=	largest

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

.PHONY: clean fclean re largest
