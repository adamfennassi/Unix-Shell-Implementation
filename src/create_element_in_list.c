/*
** EPITECH PROJECT, 2024
** src
** File description:
** mysh
*/

#include "mysh.h"

list_t *env_in_list(char **env)
{
    list_t *element = NULL;

    element = create_head(env[0]);
    for (int i = 1; env[i]; i++)
        create_list(env[i], element);
    return element;
}

list_t *create_head(char *line_env)
{
    list_t *start = malloc(sizeof(list_t));

    start->lines_env = my_strdup(line_env);
    start->next = NULL;
    start->prev = NULL;
    return start;
}

void create_list(char *data, list_t *head)
{
    list_t *chain = malloc(sizeof(list_t));

    for (; head->next != NULL; head = head->next);
    chain->prev = head;
    head->next = chain;
    chain->lines_env = my_strdup(data);
    chain->next = NULL;
}
