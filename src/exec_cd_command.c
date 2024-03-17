/*
** EPITECH PROJECT, 2024
** src
** File description:
** mysh
*/

#include "mysh.h"

int exec_cd_for_home(list_t *chain)
{
    char *home = get_env_ll(chain, "HOME=");

    home = remove_start(home, "HOME=/");
    if (home != NULL)
        chdir(home);
    else
        return 84;
    return 0;
}

int exec_cd_for_user(list_t *chain)
{
    char *user = get_env_ll(chain, "USER");

    user = remove_start(user, "USER=");
    if (user != NULL)
        chdir(user);
    else
        return 84;
    return 0;
}

int cd_with_dashe(list_t *chain)
{
    int n = 4000;
    char *buff = NULL;
    char *cwd = NULL;
    char *oldpwd_env = NULL;
    char *new_oldpwd = NULL;
    int res = 0;

    oldpwd_env = get_env_ll(chain, "OLDPWD=");
    new_oldpwd = getcwd(buff, n);
    if (oldpwd_env == NULL) {
        write(2, ": No such file or directory.\n", 29);
        return 1;
    }
    oldpwd_env = remove_start(oldpwd_env, "OLDPWD=");
    chdir(oldpwd_env);
    cwd = getcwd(buff, n);
    res = save_pwd(chain, new_oldpwd, cwd);
    return res;
}

int exec_cd_with_one_arg(list_t *chain, info_env_t *info)
{
    int n = 4000;
    char *buff = NULL;
    char *cwd = NULL;
    char *oldpwd = NULL;
    int res = 0;

    if (my_strcmp("-", info->command[1]) == 0)
        res = cd_with_dashe(chain);
    else {
        oldpwd = getcwd(buff, n);
        chdir(info->command[1]);
        cwd = getcwd(buff, n);
        res = save_pwd(chain, oldpwd, cwd);
    }
    return res;
}

int choose_just_cd(list_t *chain)
{
    int return_val;
    int res = 0;
    int n = 4000;
    char *buff = NULL;
    char *cwd = NULL;
    char *oldpwd = getcwd(buff, n);
    char **array = search_pwd(chain);

    if (array == NULL)
        return 84;
    return_val = search_just_cd(array, chain);
    cwd = getcwd(buff, n);
    res = save_pwd(chain, oldpwd, cwd);
    if (res == 0)
        return return_val;
    else
        return res;
}
