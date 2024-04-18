/*
** EPITECH PROJECT, 2024
** src
** File description:
** mysh
*/

int my_strlen(char const *str)
{
    int i = 0;
    int counter = 0;

    while (str[i] != '\0') {
        if (str[i] == '\t') {
            i++;
        }
        i++;
        counter++;
    }
    return counter;
}
