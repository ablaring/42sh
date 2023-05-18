/*
** EPITECH PROJECT, 2022
** function_edition.c
** File description:
** Function : function_edition
*/

#include "struct_all.h"
#include "my.h"

void decale_cara(char *str, int n)
{
    int len = my_strlen(str);
    for (int i = len - 1; i >= n; i--)
        str[i + 1] = str[i];
    str[n] = ' ';
}

void sigtstp_handler(__attribute__((unused))int signum)
{
    return;
}
