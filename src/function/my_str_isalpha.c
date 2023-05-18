/*
** EPITECH PROJECT, 2022
** my_str_isalpha.c
** File description:
** task12
*/
#include "my.h"

int my_strisalpha ( char const * str )
{
    int i = 0;
    int tour = 0;
    for (; str[i] != '\0'; i++){
        if ((str[i] >= 97 && str[i] <= 122) || (str[i] >= 65 && str[i] <= 90))
            tour++;
        else
            return (1);
    }
    return (0);
}

int my_letter_isalpha ( char const str )
{
    if ((str >= 97 && str <= 122) || (str >= 65 && str <= 90))
        return (0);
    else
        return (1);
}
