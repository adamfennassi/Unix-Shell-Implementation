/*
** EPITECH PROJECT, 2024
** src
** File description:
** mysh
*/
#include "mysh.h"

char *in_linked_list(list_t *list, char *word)
{
    list_t *my_list = list;

    for (; my_list; my_list = my_list->next)
        if (my_strcmp(my_list->lines_env, word) == 0)
            return my_list->lines_env;
    return NULL;
}

int home_case(list_t *chain)
{
    char *home = get_env_ll(chain, "HOME=");

    home = remove_prefix(home, "HOME=/");
    if (home != NULL)
        chdir(home);
    else
        return 84;
    return 0;
}

int user_case(list_t *chain)
{
    char *user = get_env_ll(chain, "USER");

    user = remove_prefix(user, "USER=");
    if (user != NULL)
        chdir(user);
    else
        return 84;
    return 0;
}
