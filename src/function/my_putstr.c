/*
** EPITECH PROJECT, 2022
** my_putstr
** File description:
** taks02
*/

#include <unistd.h>

void my_putchar(char c);

int my_strlen(char *str)
{
    int n = 0;
    if (str == NULL)
        return 0;
    while (str[n]) {
        n = n + 1;
    }
    return n;
}

static int my_strlen_putstr(char const *str)
{
    int n = 0;
    while (str[n]) {
        n = n + 1;
    }
    return n;
}

int my_putstr(char const *str)
{
    return write(1, str, my_strlen_putstr(str));
}
