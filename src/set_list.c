/*
** EPITECH PROJECT, 2024
** src
** File description:
** mysh
*/

#include "mysh.h"

list_t *fill_list(char **env, list_t *head)
{
    list_t *list = malloc(sizeof(list_t));

    for (int i = 1; env[i]; i++) {
        for (; head->next != NULL; head = head->next);
        list->prev = head;
        head->next = list;
        list->lines_env = my_strdup(env[i]);
        list->next = NULL;
    }
    return list;
}

list_t *init_head(char *head)
{
    list_t *init_head = malloc(sizeof(list_t));

    init_head->lines_env = my_strdup(head);
    init_head->next = NULL;
    init_head->prev = NULL;
    return init_head;
}

list_t *init_list(char **env)
{
    list_t *head = malloc(sizeof(list_t));
    list_t *env_list = NULL;

    head = init_head(env[0]);
    env_list = fill_list(env, head);
    return env_list;
}

void create_list(char *data, list_t *list)
{
    list_t *chain = malloc(sizeof(list_t));

    for (; list->next != NULL; list = list->next);
    chain->prev = list;
    list->next = chain;
    chain->lines_env = my_strdup(data);
    chain->next = NULL;
}

char *get_env_ll(list_t *list, char *word)
{
    for (; list; list = list->next)
        if (my_strcmp(word, list->lines_env) == 0)
            return list->lines_env;
    return NULL;
}
