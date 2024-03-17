/*
** EPITECH PROJECT, 2024
** src
** File description:
** mysh
*/

#include "mysh.h"

int search_cd_command(info_env_t *info, list_t *chain)
{
    int i = 0;
    int res = 0;

    for (; info->command[i]; i++);
    if (i > 2) {
        my_putstr("too many arguments\n");
        return 1;
    } else if (i == 1) {
        res = choose_just_cd(chain);
        return res;
    } else {
        res = exec_cd_with_one_arg(chain, info);
        return res;
    }
    return 0;
}

void return_back(int i)
{
    for (int x = 0; x != i; x++)
        chdir("../");
}

int search_just_cd(char **array, list_t *chain)
{
    int i = 0;
    int res = 0;

    for (; array[i]; i++);
    if (i == 1)
        res = exec_cd_for_user(chain);
    else if (i == 2)
        res = exec_cd_for_home(chain);
    else
        return_back(i);
    return res;
}

int save_pwd(list_t *chain, char *oldpwd, char *cwd)
{
    int res = 0;

    res = search_if_line_exist(chain, "OLDPWD=");
    oldpwd = my_strcat("OLDPWD=", oldpwd);
    create_list(oldpwd, chain);
    if (res == 84)
        return 84;
    res = search_if_line_exist(chain, "PWD=");
    cwd = my_strcat("PWD=", cwd);
    create_list(cwd, chain);
    if (res == 84)
        return 84;
    return 0;
}

char **search_pwd(list_t *chain)
{
    char *path = search_element_in_ll(chain, "PWD=");
    char **array = NULL;

    if (path == NULL)
        return NULL;
    path = remove_start(path, "PWD=/");
    array = my_str_to_word_array(path, '/');
    return array;
}
