/*
** EPITECH PROJECT, 2024
** src
** File description:
** mysh
*/
#include "mysh.h"

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

int execute_setenv(env_config_t *env_strct, list_t *list)
{
}

int execute_unsetenv(env_config_t *env_strct, list_t *list)
{
}

int execute_env(env_config_t *env_strct, list_t *list)
{
}
