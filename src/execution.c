/*
** EPITECH PROJECT, 2024
** src
** File description:
** mysh
*/

#include "mysh.h"

int count_letters(char *env)
{
    int i = 0;

    for (; env[i] != '\0'; i++);
    return i + 1;
}

int execute_brut_command(info_env_t *info, list_t *chain)
{
    int res = -1;

    if (my_strcmp_exactly(info->command[0], "exit") == 0) {
        my_putstr("exit\n");
        exit(0);
    }
    if (my_strcmp_exactly(info->command[0], "cd") == 0)
        res = search_cd_command(info, chain);
    if (my_strcmp_exactly(info->command[0], "setenv") == 0)
        res = search_setenv_command(chain, info);
    if (my_strcmp_exactly(info->command[0], "unsetenv") == 0)
        res = exec_unsetenv(chain, info);
    if (my_strcmp_exactly(info->command[0], "env") == 0)
        res = print_env(chain);
    return res;
}

int execute_command(info_env_t *info, list_t *chain)
{
    int res = execute_brut_command(info, chain);

    if (res == 84)
        return 84;
    else if (res == -1)
        res = create_child(info);
    return res;
}
