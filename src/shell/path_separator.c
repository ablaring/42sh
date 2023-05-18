/*
** EPITECH PROJECT, 2022
** patch_separator.c
** File description:
** Function : *
*/

#include "struct_all.h"
#include "my.h"

#include <stdio.h>
#include <string.h>

char* patch_separator(char* cmd)
{
    int len = strlen(cmd);
    int count = 0;
    for (int i = 0; i < len; i++) {
        if (cmd[i] == ';') {
            count++;
        } else {
            break;
        }
    }
    for (int i = 0; i < len - count + 1; i++)
        cmd[i] = cmd[i + count];
    return cmd;
}
