/*
** EPITECH PROJECT, 2024
** src
** File description:
** mysh
*/
#include "mysh.h"


char **get_pwd_in_ll(list_t *list)
{
    char *path = in_linked_list(list, "PWD=");
    int max_tokens = 10000;
    char **res = malloc(sizeof(char *) * max_tokens);
    int i = 0;
    char *token;

    if (path == NULL)
        return NULL;
    path = remove_prefix(path, "PWD=/");
    token = strtok(path, "/");
    while (token != NULL) {
        res[i] = my_strdup(token);
        i++;
        token = strtok(NULL, "/");
    }
    res[i] = NULL;
    return res;
}

void backing(int i)
{
    for (int x = 2; x < i; x++) {
        if (chdir("../") == -1) {
            return;
        }
    }
}

int choose_pwd(list_t *list, int i)
{
    int res = 0;

    if (i == 1) {
        res = user_case(list);
    } else if (i == 2) {
        res = home_case(list);
    } else {
        backing(i);
    }
    return res;
}

void verif_position_to_delete(list_t *element)
{
    if (element->prev == NULL)
        delete_head(element);
    else if (element->next == NULL)
        delete_tail(element);
    else
        delete_middle(element);
}

int search_if_pwd_exist(list_t *list, char *pwd)
{
    list_t *my_list = list;

    while (my_list) {
        if (my_strncmp(pwd, my_list->lines_env, my_strlen(pwd)) == 0) {
            verif_position_to_delete(my_list);
            return 0;
        } else {
            my_list = my_list->next;
        }
    }
    return 84;
}
