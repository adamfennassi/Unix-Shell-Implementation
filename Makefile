##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## mysh
##

SRC 	=	src/main.c\
			src/my_strdup.c\
			src/my_strlen.c\
			src/get_env.c\
			src/set_list.c\

OBJ	=	$(SRC:.c=.o)

NAME	=	mysh

INCLUDES	=	-I includes/

CFLAGS	=	$(INCLUDES) -Wall -Wextra -g

all: 	$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: 	fclean all
