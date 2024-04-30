/*
** EPITECH PROJECT, 2024
** src
** File description:
** mysh
*/
#include "mysh.h"

int simple_setenv(list_t *list, env_config_t *env_strct)
{
    char *line_to_add = my_strcat(env_strct->line_cmd[1], "=");
    int res = 0;

    printf("%s\n", env_strct->line_cmd[1]);
    if (line_to_add == NULL)
        return 84;
    res = search_if_pwd_exist(list, line_to_add);
    create_list(line_to_add, list);
    return res;
}

int setenv_line(list_t *chain, env_config_t *env_strct)
{
    char *line_to_add = my_strcat(env_strct->line_cmd[1], "=");
    int res = 0;

    if (line_to_add == NULL)
        return 84;
    printf("%s\n", env_strct->line_cmd[1]);
    res = search_if_pwd_exist(chain, line_to_add);
    line_to_add = my_strcat(line_to_add, env_strct->line_cmd[2]);
    create_list(line_to_add, chain);
    return res;
}

int print_env(list_t *chain)
{
    for (; chain; chain = chain->next) {
        my_putstr(chain->lines_env);
        my_putstr("\n");
    }
    return 0;
}
