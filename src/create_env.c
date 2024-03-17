/*
** EPITECH PROJECT, 2024
** src
** File description:
** mysh
*/

#include "mysh.h"

char **create_env_informations(char **env, info_env_t *env_info)
{
    char *path;

    env_info->env = create_env(env);
    if (env_info->env == NULL)
        return NULL;
    path = get_env(env_info->env, "PATH=");
    if (path == NULL)
        return NULL;
    path = remove_start(path, "PATH=");
    if (path == NULL)
        return NULL;
    env_info->path = my_str_to_word_array(path, ':');
    if (env_info->path == NULL)
        return NULL;
    return env_info->path;
}

char *get_env(char **env, char *word)
{
    int i = 0;

    for (; env[i]; i++)
        if (my_strcmp(word, env[i]) == 0)
            return env[i];
    return NULL;
}

char **create_env(char **env)
{
    char **array_env;
    int i = 0;
    int y = 0;

    for (; env[i]; i++);
    array_env = malloc(sizeof(char *) * (i + 1));
    if (array_env == NULL)
        return NULL;
    array_env[i] = NULL;
    for (int x = 0; x < i; x++) {
        array_env[x] = malloc(sizeof(char) * (count_letters(env[x])));
        if (array_env[x] == NULL)
            return NULL;
        for (; env[x][y] != '\0'; y++)
            array_env[x][y] = env[x][y];
        array_env[x][y] = '\0';
        y = 0;
    }
    return array_env;
}

char *get_env_ll(list_t *chain, char *word)
{
    for (; chain; chain = chain->next)
        if (my_strcmp(word, chain->lines_env) == 0)
            return chain->lines_env;
    return NULL;
}

int print_env(list_t *chain)
{
    for (; chain; chain = chain->next) {
        my_putstr(chain->lines_env);
        my_putchar('\n');
    }
    return 0;
}
