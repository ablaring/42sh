/*
** EPITECH PROJECT, 2022
** get_or_and.c
** File description:
** Function : *
*/

#include "struct_all.h"
#include "my.h"

char *reset_line_cmd_or_and(char *cmd)
{
    for (int n = 0; cmd[n] != '\0'; n++)
        if (cmd[n] == 27)
            cmd[n] = '|';
    return cmd;
}

char **reset_cmd_or_and(i_s *info_shell, char **tab_cmd)
{
    for (int n = 0; n < info_shell->st_cond.size_cmd_and_or; n++)
        tab_cmd[n] = reset_line_cmd_or_and(tab_cmd[n]);
    return tab_cmd;
}

char **get_cmd_or_and(i_s *info_shell, char *cmd)
{
    for (int n = 1; cmd[n] != '\0'; n++)
        if (cmd[n - 1] != '|' && cmd[n] == '|' && cmd[n + 1] != '|')
            cmd[n] = 27;
    char **cmd_and_or = NULL;
    int size_cmd_and_or = 0;
    char *phrase = strtok(cmd, "&&||");
    while (phrase != NULL) {
        cmd_and_or = realloc(cmd_and_or, sizeof(char *) *
            (size_cmd_and_or + 1));
        cmd_and_or[size_cmd_and_or] = strdup(phrase);
        size_cmd_and_or++;
        phrase = strtok(NULL, "&&||");
    }
    info_shell->st_cond.size_cmd_and_or = size_cmd_and_or;
    for (int i = 0; i < size_cmd_and_or; i++) {
        int len = my_strlen(cmd_and_or[i]);
        cmd_and_or[i] = realloc(cmd_and_or[i], len + 1);
        cmd_and_or[i][len] = '\0';
    }
    return reset_cmd_or_and(info_shell, cmd_and_or);
}

char **get_or_and(i_s *info_shell, char *cmd)
{
    char **tab_or_and = malloc(sizeof(char *) * (my_strlen(cmd)));
    for (int n = 0; n < my_strlen(cmd); n++)
        tab_or_and[n] = malloc(sizeof(char) * 1);
    int pos = 0;
    for (int n = 0; cmd[n] != '\0'; n++) {
        if (cmd[n] == '&' && cmd[n + 1] == '&') {
            tab_or_and[pos][0] = '&';
            pos++;
        }
        if (cmd[n] == '|' && cmd[n + 1] == '|') {
            tab_or_and[pos][0] = '|';
            pos++;
        }
    }

    info_shell->st_cond.size_and_or = (pos + 1);
    return tab_or_and;
}
