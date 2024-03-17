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

typedef struct list_s {
    char *lines_env;
    struct list_s *next;
    struct list_s *prev;
} list_t;

typedef struct info_env_s {
    char **path;
    char **command;
    char *execute;
    char **env;
    int ret;
} info_env_t;
int minishell_config(char **env);
int execute_command(info_env_t *info, list_t *chain);
int delete_line_middle(list_t *element);
int delete_tail(list_t *element);
int delete_head(list_t *element);
int choose_just_cd(list_t *chain);
int exec_cd_with_one_arg(list_t *chain, info_env_t *info);
int cd_with_dashe(list_t *chain);
int exec_cd_for_user(list_t *chain);
int exec_cd_for_home(list_t *chain);
int save_pwd(list_t *chain, char *oldpwd, char *cwd);
int search_cd_command(info_env_t *info, list_t *chain);
int search_just_cd(char **array, list_t *chain);
char **search_pwd(list_t *chain);
int create_child(info_env_t *info);
char **create_env_informations(char **env, info_env_t *env_info);
int print_env(list_t *chain);
char *get_env_ll(list_t *chain, char *word);
char **create_env(char **env);
char *get_env(char **env, char *word);
void my_putchar(char c);
int my_putstr(char const *str);
char **my_str_to_word_array(char *buffer, char c);
char *my_strcat(char *dest, char const *src);
int my_strcmp_exactly(char *word, char *comparator);
int my_strcmp(char *word, char *comparator);
char *my_strdup(char *data);
int my_strlen(char const *str);
list_t *create_head(char *line_env);
void create_list(char *data, list_t *head);
list_t *env_in_list(char **env);
int search_position(list_t *element);
char *search_element_in_ll(list_t *chain, char *search);
char *remove_end(char *str);
char *remove_start(char *str, char *delete);
int search_if_line_exist(list_t *chain, char *line);
int add_to_env_one_info(list_t *chain, info_env_t *info);
int add_to_env_line(list_t *chain, info_env_t *info);
int search_setenv_command(list_t *chain, info_env_t *info);
int exec_unsetenv(list_t *chain, info_env_t *info);
int count_letters(char *env);

#endif /* MINISHELL_H_ */
