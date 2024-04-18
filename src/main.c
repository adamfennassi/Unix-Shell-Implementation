/*
** EPITECH PROJECT, 2024
** src
** File description:
** mysh
*/
#include "mysh.h"

int lunch_shell(list_t *list, env_config_t *env_strct)
{
}

char **init_env(char **env, env_config_t *env_strct)
{
    char *path;
    char *new_path = NULL;
    int num_tokens = 0;
    char *token;
    int i = 0;

    env_strct->env = get_env(env);
    path = get_path(env);
    new_path = remove_path(path);
    for (char *ptr = strtok(new_path, ":");
    ptr != NULL; ptr = strtok(NULL, ":"))
        num_tokens++;
    env_strct->path = malloc(sizeof(char *) * (num_tokens + 1));
    for (token = strtok(new_path, ":");
    token != NULL; token = strtok(NULL, ":")) {
        env_strct->path[i] = my_strdup(token);
        i++;
    }
    env_strct->path[num_tokens] = NULL;
    return env_strct->path;
}

int main(int ac, char **av, char **env)
{
    env_config_t *env_struct = malloc(sizeof(env_config_t));
    list_t *shell_list = malloc(sizeof(list_t));

    if (ac != 1)
        return 84;
    if (init_env(env, env_struct) == NULL)
        return 84;
    shell_list = init_list(env);
    return lunch_shell(shell_list, env_struct);
}
