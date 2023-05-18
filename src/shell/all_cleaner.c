/*
** EPITECH PROJECT, 2022
** all_cleaner.c
** File description:
** Function : all_cleaner
*/

#include "struct_all.h"
#include "my.h"

char *my_cleaner(char *cmd)
{
    cmd = cleaner_backsticks(cmd);
    cmd = cleaner_parentheses(cmd);
    deb_cleaner(cmd);
    int i = 0;
    int j = 0;
    int len = my_strlen(cmd);
    char *temp = malloc(sizeof(char) * (len + 2));
    if (cmd[0] == '\0') {
        free(temp);
        return cmd;
    }
    for (i = 0; i < len; i++)
        if (cmd[i] != ' ' || (cmd[i] == ' ' && cmd[i + 1] != ' '))
        temp[j++] = cmd[i];
    temp[j] = '\0';
    free(cmd);
    cmd = malloc(sizeof(char) * (my_strlen(temp) + 2));
    my_strcpy(cmd, temp);
    free(temp);
    return cmd;
}

char *my_cleaner_tab(char *cmd)
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
        return cmd;
    while (cmd[(my_strlen(cmd) - 1)] != '\0' &&
        cmd[(my_strlen(cmd) - 1)] == ' ') {
        cmd[(my_strlen(cmd) - 1)] = '\0';
    }
    return cmd;
}

char *sub_cleaner_and_patch(char *cmd, int len, int k)
{
    while (cmd[0] == ';') {
        for (k = 1; k < len; k++)
            cmd[k - 1] = cmd[k];
        len--;
    }
    while (cmd[len] == ';') {
        len--;
    }
    if (isatty(0) == 1)
        cmd[len + 1] = '\0';
    return cmd;
}

char *suite_cleaner_and_patch(char *cmd, int i, int len, int j)
{
    for (j = i + 1; j < len; j++) {
        cmd[j] = cmd[j + 1];
    }
    return (cmd);
}

int cleaner_and_patch(char *cmd)
{
    int i = 0;
    int j = 0;
    int k = 0;
    j = 0;
    int len = my_strlen(cmd);
    for (i = 0; i < len - 1; i++) {
        if (cmd[i] == ';' && cmd[i + 1] == ';') {
            cmd = suite_cleaner_and_patch(cmd, i, len, j);
            len--;
            i--;
        }
    }
    cmd = patch_separator(cmd);
    cmd = sub_cleaner_and_patch(cmd, len, k);
    for (int n = 0; cmd[n] != '\0'; n++) {
        if (cmd[n] != ';' && cmd[n] != '\n')
            return 0;
    }
    return 1;
}
