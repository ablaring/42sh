/*
** EPITECH PROJECT, 2022
** sub_and_or.c
** File description:
** Function : *
*/

#include "struct_all.h"
#include "my.h"

void delete_prefix(char* str, int n)
{
    int i = 0;
    while (str[i + n] != '\0') {
        str[i] = str[i + n];
        i++;
    }
    str[i] = '\0';
}

char *cleaner_and_or(char *cmd)
{
    int good = 0;
    for (int n = 0; my_strlen(cmd) > n; n++) {
        if (cmd[n] != '&' && cmd[n] != ' ')
            good = 1;
        if (good == 0 && cmd[n] == '&' && cmd[n + 1] == '&')
            delete_prefix(cmd, n + 2);
    }
    return cmd;
}
