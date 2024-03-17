##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## mysh
##

SRC 	=	src/main.c\
			src/execution.c	\
			src/exec_cd_command.c\
			src/save_pwd.c\
			src/create_child.c\
			src/create_env.c\
			src/my_putstr.c\
		 	src/my_str_to_word_array.c\
		 	src/my_strcat.c\
		 	src/my_strcmp.c\
			src/my_strdup.c\
			src/my_strlen.c\
			src/create_element_in_list.c\
			src/search.c\
			src/remove_start.c\
			src/exec_setenv.c\
			src/exec_unsetenv.c\
			src/delete.c\

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
