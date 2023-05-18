/*
** EPITECH PROJECT, 2022
** sub_boucle_shell.c
** File description:
** Function : shell
*/

#include "struct_all.h"
#include "my.h"

char *name_base(char *name)
{
    int i = strlen(name);
    int j = 0;
    char *base = malloc(sizeof(char *) * i);
    for (; name[i] != '/'; i--);
    for (i = i + 1; name[i] != '\0'; i++, j++)
        base[j] = name[i];
    base[j] = '\0';
    return base;
}
