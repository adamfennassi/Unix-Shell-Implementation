/*
** EPITECH PROJECT, 2024
** src
** File description:
** mysh
*/
#include "mysh.h"

int save_it(list_t *list, char *oldpwd, char *current_pwd)
{
    int res = 0;

    res = search_if_pwd_exist(list, "OLDPWD=");
    oldpwd = my_strcat("OLDPWD=", oldpwd);
    create_list(oldpwd, list);
    if (res == 84)
        return 84;
    res = search_if_pwd_exist(list, "PWD=");
    current_pwd = my_strcat("PWD=", current_pwd);
    create_list(current_pwd, list);
    if (res == 84)
        return 84;
    return 0;
}

int simple_cd(list_t *list)
{
    char *buffer = NULL;
    int size = 6000;
    char *oldpwd = getcwd(buffer, size);
    char *current_pwd;
    char **pwd_array = get_pwd_in_ll(list);
    int i = 0;
    int value = 0;
    int value_2 = 0;

    if (pwd_array == NULL)
        return 84;
    for (; pwd_array[i]; i++);
    value = choose_pwd(list, i);
    current_pwd = getcwd(buffer, size);
    value_2 = save_it(list, oldpwd, current_pwd);
    if (value_2 == 0)
        return value;
    else
        return value_2;
}

int previous_cd(list_t *chain)
{
    int n = 6000;
    char *buff = NULL;
    char *cwd = NULL;
    char *oldpwd_env = NULL;
    char *current_pwd = NULL;
    int res = 0;

    oldpwd_env = get_env_ll(chain, "OLDPWD=");
    if (oldpwd_env == NULL) {
        my_putstr(": No such file or directory.\n");
        return 84;
    }
    current_pwd = getcwd(buff, n);
    oldpwd_env = remove_prefix(oldpwd_env, "OLDPWD=");
    chdir(oldpwd_env);
    cwd = getcwd(buff, n);
    res = save_it(chain, current_pwd, cwd);
    return res;
}

int arg_cd(env_config_t *env_struct, list_t *list)
{
    int n = 6000;
    char *buffer = NULL;
    char *current_pwd = NULL;
    char *oldpwd = NULL;
    int value;

    if (my_strcmp("-", env_struct->line_cmd[1]) == 0)
        value = previous_cd(list);
    else {
        oldpwd = getcwd(buffer, n);
        chdir(env_struct->line_cmd[1]);
        current_pwd = getcwd(buffer, n);
        value = save_it(list, oldpwd, current_pwd);
    }
    return value;
}
