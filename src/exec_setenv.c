/*
** EPITECH PROJECT, 2024
** src
** File description:
** mysh
*/

#include "mysh.h"

int search_setenv_command(list_t *chain, info_env_t *info)
{
    int res = 0;

    if (info->command[1] == NULL) {
        res = print_env(chain);
        return res;
    }
    if (info->command[2] == NULL) {
        res = add_to_env_one_info(chain, info);
        return res;
    }
    if (info->command[3] == NULL) {
        res = add_to_env_line(chain, info);
        return res;
    }
    if (info->command[3] != NULL) {
        write(2, "too many arguments\n", 19);
        return 1;
    }
    return res;
}

int add_to_env_one_info(list_t *chain, info_env_t *info)
{
    char *line_to_add = my_strcat(info->command[1], "=");
    int res = 0;

    if (line_to_add == NULL)
        return 84;
    res = search_if_line_exist(chain, line_to_add);
    create_list(line_to_add, chain);
    return res;
}

int add_to_env_line(list_t *chain, info_env_t *info)
{
    char *line_to_add = my_strcat(info->command[1], "=");
    int res = 0;

    if (line_to_add == NULL)
        return 84;
    res = search_if_line_exist(chain, line_to_add);
    line_to_add = my_strcat(line_to_add, info->command[2]);
    create_list(line_to_add, chain);
    return res;
}
