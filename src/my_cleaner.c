/*
** EPITECH PROJECT, 2022
** my_cleaner.c
** File description:
** Function : my_cleaner
*/

#include "struct_all.h"
#include "my.h"

void deb_cleaner(char *cmd)
{
    for (int n = 0; cmd[n] != '\0'; n++) {
        if (cmd[n] == '\t')
            cmd[n] = ' ';
        if (cmd[n] == '\n')
            cmd[n] = '\0';
    }
    while (cmd[0] == ' ') {
        for (int n = 0; cmd[n] != '\0'; n++)
            cmd[n] = cmd[n + 1];
    }
    if (cmd[0] == '\0')
        return;
    while (cmd[(my_strlen(cmd) - 1)] != '\0' &&
        cmd[(my_strlen(cmd) - 1)] == ' ') {
        cmd[(my_strlen(cmd) - 1)] = '\0';
    }
}
