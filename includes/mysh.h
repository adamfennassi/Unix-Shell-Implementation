/*
** EPITECH PROJECT, 2024
** src
** File description:
** mysh
*/

#ifndef MINISHELL_H_
    #define MINISHELL_H_
    #include <string.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <sys/types.h>
    #include <sys/wait.h>
    #include <errno.h>
    #include <stdio.h>

typedef struct list {
    char *lines_env;
    struct list *next;
    struct list *prev;
}list_t;

typedef struct env_config {
    char **path;
    char **line_cmd;
    char *execute;
    char **env;
    int ret;
} env_config_t;

char *my_strdup(char *data);
int my_strlen(char const *str);
int my_putstr(char const *str);

char *remove_path(char *str);
int get_len(char **env);
int nb_letters(char *env);
char **get_env(char **env);
char *get_path(char **env);

list_t *fill_list(char **env, list_t *head);
list_t *init_head(char *head);
list_t *init_list(char **env);
#endif /* MINISHELL_H_ */
