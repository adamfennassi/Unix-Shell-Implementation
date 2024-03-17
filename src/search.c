/*
** EPITECH PROJECT, 2024
** src
** File description:
** mysh
*/

#include "mysh.h"

int search_if_line_exist(list_t *chain, char *line)
{
    list_t *to_find = chain;
    int res = 0;

    while (to_find) {
        if (my_strcmp(line, to_find->lines_env) == 0) {
            res = search_position(to_find);
            return res;
        } else
            to_find = to_find->next;
    }
    return 0;
}

int search_position(list_t *element)
{
    if (element->prev == NULL)
        return delete_head(element);
    else if (element->next == NULL)
        return delete_tail(element);
    else
        return delete_line_middle(element);
}

char *search_element_in_ll(list_t *chain, char *search)
{
    list_t *to_find = chain;

    for (; to_find; to_find = to_find->next)
        if (my_strcmp(to_find->lines_env, search) == 0)
            return to_find->lines_env;
    return NULL;
}
