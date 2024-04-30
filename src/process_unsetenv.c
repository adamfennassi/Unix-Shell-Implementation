/*
** EPITECH PROJECT, 2024
** src
** File description:
** mysh
*/
#include "mysh.h"

int unsetenv_many(list_t *list, env_config_t *env_strct)
{
    for (int i = 1; env_strct->line_cmd[i] != NULL; i++) {
        env_strct->line_cmd[i] = my_strcat(env_strct->line_cmd[i], "=");
    }
    for (int i = 1; env_strct->line_cmd[i] != NULL; i++) {
        search_if_pwd_exist(list, env_strct->line_cmd[i]);
        }
    return 0;
}
