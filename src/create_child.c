/*
** EPITECH PROJECT, 2024
** src
** File description:
** mysh
*/

#include "mysh.h"

int access_is_possible(char *str)
{
    if (access(str, F_OK) == 0 && access(str, X_OK) == 0
        && access(str, R_OK) == 0)
        return 0;
    else
        return 84;
}

int choose_command(info_env_t *info)
{
    if (info->command[0][0] == '.' || info->command[0][0] == '/') {
        if (access_is_possible(info->command[0]) == 0) {
            info->execute = info->command[0];
            return 0;
        } else
            return 84;
    }
    for (int i = 0; info->path[i]; i++) {
        info->execute = my_strcat(info->path[i], "/");
        info->execute = my_strcat(info->execute, info->command[0]);
        if (access_is_possible(info->execute) == 0)
            return 0;
    }
    return 0;
}

int error_checker(int status, info_env_t *info)
{
    if (WTERMSIG(status) == 32) {
        write(2, info->command[0], my_strlen(info->command[0]));
        write(2, ": Command not found.\n", 21);
        return 1;
    }
    if (WTERMSIG(status) == 8) {
        write(2, "Floating execption", 18);
    } else
        write(2, strsignal(WTERMSIG(status)),
        my_strlen(strsignal(WTERMSIG(status))));
    if (WCOREDUMP(status))
        write(2, " (core dumped)", 14);
    write(2, "\n", 1);
    return 0;
}

int check_child_status(int status, info_env_t *info)
{
    int res;

    if (WIFSIGNALED(status)) {
        res = error_checker(status, info);
        if (res != 0)
            return res;
        if (WTERMSIG(status) == 8)
            return 136;
        return status;
    } else {
        return 0;
    }
}

int create_child(info_env_t *info)
{
    int res = choose_command(info);
    pid_t child;
    int status;

    if (res != 0)
        return 84;
    child = fork();
    if (child == 0) {
        execve(info->execute, info->command, info->env);
    } else if (child == -1) {
        my_putstr("error");
        return 84;
    } else {
        waitpid(child, &status, 0);
    }
    return check_child_status(status, info);
}
