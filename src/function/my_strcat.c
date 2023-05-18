/*
** EPITECH PROJECT, 2022
** task02
** File description:
** task02
*/

#include <stdlib.h>

int counter(char *str)
{
    int i = 0;

    for (; str[i]; i++);
    return i;
}

char *my_strcat(char *dest, char *src)
{
    int longu_1 = counter(dest);
    int longu_2 = counter(src);
    int longu_tot = longu_1 + longu_2;
    char *res = malloc(sizeof(char) * (longu_tot + 2));
    int i = 0;
    for (int cpt = 0; cpt < longu_1; cpt++) {
        res[i] = dest[i];
        i++;
    }
    for (int cpt = 0; cpt < longu_2; cpt++) {
        res[i] = src[cpt];
        i++;
    }
    res[i] = '\0';
    return (res);
}
