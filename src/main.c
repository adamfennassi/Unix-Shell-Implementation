/*
** EPITECH PROJECT, 2024
** src
** File description:
** mysh
*/

#include "mysh.h"

void put_exit_or_not(int ret_value)
{
    if (ret_value == -1 && isatty(0) == 1)
        my_putstr("exit\n");
}

int contains_only_whitespace(const char *str)
{
    while (*str) {
        if (!(*str == ' ' || *str == '\t')) {
            return 0;
        }
        str++;
    }
    return 1;
}

int create_prompt_command(info_env_t *info, list_t *chain)
{
    char *lineptr = NULL;
    size_t n = 0;
    int return_value = 0;

    while (1) {
        if (isatty(0) == 1)
            my_putstr("$> ");
        return_value = getline(&lineptr, &n, stdin);
        if (return_value == -1) {
            put_exit_or_not(return_value);
            return 0;
        }
        lineptr = remove_end(lineptr);
        if (lineptr == NULL || lineptr[0] == '\0' ||
        contains_only_whitespace(lineptr))
            continue;
        info->command = my_str_to_word_array(lineptr, ' ');
        info->ret = execute_command(info, chain);
    }
    return info->ret;
}

int minishell_config(char **env)
{
    list_t *list = NULL;
    info_env_t *env_info = malloc(sizeof(info_env_t));
    int value = 0;

    if (create_env_informations(env, env_info) == NULL) {
        write(2, "Error with read env\n", 20);
        return 84;
    }
    list = env_in_list(env_info->env);
    value = create_prompt_command(env_info, list);
    return value;
}

int main(int ac, char **av, char **env)
{
    int value;

    if (ac != 1) {
        my_putstr("ERROR : too many command.\n");
        return 84;
    } else {
        value = minishell_config(env);
        return value;
    }
}
