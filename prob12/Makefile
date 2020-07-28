##
## PERSONAL PROJECT, 2019
## hdtn
## File description:
## Makefile 
##

SRC	=	main_hdtn.c	\

OBJ	=	$(SRC:.c=.o)

CC	=	@gcc

CFLAGS	=	-Wall -Werror -Wextra --pedantic

NAME	=	hdtn

.PHONY: clean fclean re hdtn

all: $(NAME)

$(NAME): $(OBJ)
	@echo Compiling \'$(NAME)\'
	$(CC) -o $(NAME) $(OBJ)
	@echo \'$(NAME)\' compiled successfully

clean:
	@rm -rf $(OBJ)
	@echo Cleaned .o for \'$(NAME)\'

fclean:	clean
	@rm -rf $(NAME)
	@echo Cleaned \'$(NAME)\'

re: fclean all
