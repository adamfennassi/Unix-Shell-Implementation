/*
** EPITECH PROJECT, 2024
** src
** File description:
** mysh
*/
#include "mysh.h"


int execute_setenv(env_config_t *env_strct, list_t *list)
{
}

int execute_unsetenv(env_config_t *env_strct, list_t *list)
{
}

int execute_env(env_config_t *env_strct, list_t *list)
{
    int res = 0;

    if (env_strct->line_cmd[1] == NULL) {
        res = print_env(list);
        return res;
    }
    if (env_strct->line_cmd[2] == NULL) {
        res = add_to_env_one_info(list, env_strct);
        return res;
    }
    if (env_strct->line_cmd[3] == NULL) {
        res = add_to_env_line(list, list);
        return res;
    }
    if (env_strct->line_cmd[3] != NULL) {
        write(2, "too many arguments\n", 19);
        return 1;
    }
    return res;
}

int execute_cd(env_config_t *env_strct, list_t *list)
{
    int nb_arg = 0;
    int value;

    for (; env_strct->line_cmd[nb_arg]; nb_arg++);
    if (nb_arg > 2) {
        my_putstr("bash : cd: too many arguments\n");
        return 1;
    } else if (nb_arg == 1) {
        value = simple_cd(list);
        return value;
    } else {
        value = arg_cd(env_strct, list);
        return value;
    }
}

int is_cmd(env_config_t *env_strct, list_t *list)
{
    int value = -1;

    if (my_strcmp(env_strct->line_cmd[0], "cd") == 0)
        value = execute_cd(env_strct, list);
    if (my_strcmp(env_strct->line_cmd[0], "exit") == 0) {
        my_putstr("exit\n");
        exit(0);
    }
    if (my_strcmp(env_strct->line_cmd[0], "env") == 0)
        value = execute_env(env_strct, list);
    if (my_strcmp(env_strct->line_cmd[0], "unsetenv") == 0)
        value = execute_unsetenv(env_strct, list);
    if (my_strcmp(env_strct->line_cmd[0], "setenv") == 0)
        value = execute_setenv(env_strct, list);
    return value;
}
