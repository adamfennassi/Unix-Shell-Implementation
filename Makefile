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
			src/my_putstr.c\
			src/utils.c\
			src/gestion_child.c\
			src/gestion_cmd.c\
			src/my_strcmp.c\
			src/process_cd.c\
			src/cd_utils.c\
			src/my_strcat.c\
			src/launch_child.c\
			src/process_env.c\
			src/cd_utils_2.c\
			src/process_setenv.c\
			src/process_unsetenv.c\
			src/without_tab_space.c\

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
