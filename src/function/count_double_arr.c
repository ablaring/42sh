/*
** EPITECH PROJECT, 2023
** count_double_arr.c
** File description:
** desc
*/

#include "my.h"

int count_double_arr(char **arr)
{
    int i = 0;
    for (; arr[i] != NULL; i++);
    return i;
}
