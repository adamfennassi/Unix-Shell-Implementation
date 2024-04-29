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
    int return_value;
} env_config_t;

char *my_strdup(char *data);
int my_strlen(char const *str);
int my_putstr(char const *str);
char *remove_end_of_line(char *str);
void line_to_token(env_config_t *env, char *line);
int my_strcmp(char *s1, char *s2);
char *my_strcat(char *dest, char const *src);

char *remove_prefix(char *str, char *);
int get_len(char **env);
int nb_letters(char *env);
char **get_env(char **env);
char *get_path(char **env);

list_t *fill_list(char **env, list_t *head);
list_t *init_head(char *head);
list_t *init_list(char **env);
void create_list(char *data, list_t *head);

int is_cmd(env_config_t *env_strct, list_t *list);
int simple_cd(list_t *list);
int arg_cd(env_config_t *env_strct, list_t *list);

int delete_head(list_t *element);
int delete_middle(list_t *element);
int delete_tail(list_t *element);

char **get_pwd_in_ll(list_t *list);
int choose_pwd(list_t *list, int i);
void verif_position(list_t *element);
int search_if_pwd_exist(list_t *list, char *pwd);
char *in_linked_list(list_t *list, char *word);
int home_case(list_t *chain);
int user_case(list_t *chain);
char *get_env_ll(list_t *list, char *word);

int add_to_env_line(list_t *chain, env_config_t *env_strct);
int add_to_env_one_info(list_t *list, env_config_t *env_strct);
int print_env(list_t *chain);
#endif /* MINISHELL_H_ */
