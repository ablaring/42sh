/*
** EPITECH PROJECT, 2022
** my_itoa.c
** File description:
** my_itoa
*/

#include "my.h"

char *my_itoa(int nb)
{
    if (nb == 0)
        return ("0");
    char *str = malloc(sizeof(char) * 100);
    int i = 0;
    int j = 0;
    int k = 0;
    int tmp = nb;
    for (i = 0; tmp > 0; i++)
        tmp /= 10;
    for (j = 0; j < i; j++)
        str[j] = '0';
    str[j] = '\0';
    for (j = i - 1; j >= 0; j--){
        k = nb % 10;
        nb /= 10;
        str[j] = k + '0';
    }
    return (str);
}
