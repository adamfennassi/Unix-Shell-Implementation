/*
** EPITECH PROJECT, 2024
** src
** File description:
** mysh
*/
#include "mysh.h"

char *remove_end_of_line(char *str)
{
    size_t len = strlen(str);
    int i = len;

    while (i > 0 && (str[i - 1] == ' ' || str[i - 1] == '\t' ||
    str[i - 1] == '\n')) {
        i--;
    }
    if (i > 0) {
        str[i] = '\0';
    }
    return str;
}

void line_to_token(env_config_t *env, char *line)
{
    char *token;
    int max_tokens = 100000;
    int i = 0;

    env->line_cmd = malloc(sizeof(char *) * max_tokens);
    token = strtok(line, " ");
    while (token != NULL) {
        env->line_cmd[i] = my_strdup(token);
        token = strtok(NULL, " ");
        i++;
    }
}

int delete_head(list_t *element)
{
    element->next->prev = NULL;
    free(element);
    return 0;
}

int delete_tail(list_t *element)
{
    element->prev->next = NULL;
    free(element);
    return 0;
}

int delete_middle(list_t *element)
{
    element->next->prev = element->prev;
    element->prev->next = element->next;
    free(element);
    return 0;
}
