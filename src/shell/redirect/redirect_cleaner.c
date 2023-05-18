/*
** EPITECH PROJECT, 2022
** redirect_cleaner.c
** File description:
** Function : redirect_cleaner_cmd
*/

#include "struct_all.h"
#include "my.h"

char *suite_redirect_cleaner_cmd_suite(char *cmd)
{
    int n = 0;
    for (; cmd[n] != '\0' && cmd[n] != '<' && cmd[n] != '>'; n++);
    if (cmd[n] != '\0') {
        int i = n + 2;
        if (cmd[n + 1] == '>' || cmd[n + 1] == '<')
            i++;
        for (; cmd[i] != '\0' && cmd[i] != ' ' && cmd[i] != '>' &&
            cmd[i] != '<' && cmd[i] != '|'; i++);
        while (cmd[i - 1] != '\0') {
            cmd[n] = cmd[i];
            i++;
            n++;
        }
    }
    int a = 0;
    for (; cmd[a] != '\0'; a++);
    if (cmd[a - 1] == ' ')
        cmd[a - 1] = '\0';
    return cmd;
}

char * add_space_redirect(char *cmd)
{
    int nb_ocu = 0;
    int b = 0;
    for (int i = 0; cmd[i]; i++) {
        if ((cmd[i] == '>' || cmd[i] == '<') && (cmd[i + 1] &&
        cmd[i + 1] != '>' && cmd[i + 1] != '<'))
            nb_ocu++;
    }
    char *res = malloc(sizeof(char) * (strlen(cmd) + nb_ocu + 1));
    for (int i = 0; cmd[i]; i++, b++) {
        res[b] = cmd[i];
        if ((cmd[i] == '>' || cmd[i] == '<') && (cmd[i + 1] != '>' &&
        cmd[i + 1] != '<')) {
            res[b + 1] = ' ';
            b++;
        }
    }
    res[b] = '\0';
    return res;
}

char *redirect_cleaner_cmd(char *cmd)
{
    int n = 0;
    for (; cmd[n] != '\0' && cmd[n] != '<' && cmd[n] != '>'; n++);
    if (cmd[n] != '\0') {
        int i = n + 2;
        if (cmd[n + 1] == '>' || cmd[n + 1] == '<')
            i++;
        for (; cmd[i] != '\0' && cmd[i] != ' ' && cmd[i] != '>' &&
            cmd[i] != '<' && cmd[i] != '|'; i++);
        while (cmd[i - 1] != '\0') {
            cmd[n] = cmd[i];
            i++;
            n++;
        }
    } int a = 0;
    for (; cmd[a] != '\0'; a++);
    if (cmd[a - 1] == ' ')
        cmd[a - 1] = '\0';
    return suite_redirect_cleaner_cmd_suite(cmd);
}
