/*
** EPITECH PROJECT, 2024
** src
** File description:
** mysh
*/
#include "mysh.h"


int execute_setenv(env_config_t *env_strct, list_t *list)
{
    int res = 0;

    if (env_strct->line_cmd[1] == NULL) {
        res = print_env(list);
        return res;
    }
    if (env_strct->line_cmd[2] == NULL) {
        res = simple_setenv(list, env_strct);
        return res;
    }
    if (env_strct->line_cmd[3] == NULL) {
        res = setenv_line(list, env_strct);
        return res;
    }
    if (env_strct->line_cmd[3] != NULL) {
        my_putstr("setenv: too many arguments\n");
        return 1;
    }
    return res;
}

int execute_unsetenv(list_t *list, env_config_t *env_strct)
{
    if (env_strct->line_cmd[1] == NULL) {
        return 84;
    }
    if (env_strct->line_cmd[2] != NULL) {
        return unsetenv_many(list, env_strct);
    } else {
        env_strct->line_cmd[1] = my_strcat(env_strct->line_cmd[1], "=");
        search_if_pwd_exist(list, env_strct->line_cmd[1]);
    }
    return 0;
}

int execute_env(env_config_t *env_strct, list_t *list)
{
    int res = 0;

    if (env_strct->line_cmd[1] == NULL) {
        res = print_env(list);
        return res;
    } else {
        return 84;
    }
}

int execute_cd(env_config_t *env_strct, list_t *list)
{
    int nb_arg = 0;
    int value;

    for (; env_strct->line_cmd[nb_arg]; nb_arg++);
    if (nb_arg > 2) {
        my_putstr("bash : cd: too many arguments\n");
        return 1;
    } else if (nb_arg == 1 || my_strcmp(env_strct->line_cmd[1], "~") == 0) {
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
        value = execute_unsetenv(list, env_strct);
    if (my_strcmp(env_strct->line_cmd[0], "setenv") == 0)
        value = execute_setenv(env_strct, list);
    return value;
}
