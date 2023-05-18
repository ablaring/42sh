/*
** EPITECH PROJECT, 2022
** fun_or_and.c
** File description:
** Function : *
*/

#include "struct_all.h"
#include "my.h"

int verif_simple_and_or(char *cmd, i_s *info_shell)
{
    if (my_strlen(cmd) < 3)
        return 0;
    for (int n = 1; cmd[n] != '\0'; n++) {
        if (cmd[n - 1] != '&' && cmd[n] == '&' && cmd[n + 1] != '&') {
            info_shell->return_value = 1;
            return write_error_rep("Invalid null command.\n");
        }
    }
    return 0;
}

void sub_verif_syntax_and_or(int condi, int tmp_and, int tmp_or)
{
    if (condi != 0 && (tmp_and != 0 || tmp_or != 0))
        write_error_rep("Invalid null command.\n");
}

int verif_syntax_and_or(char *cmd, int word, int tmp_and, int tmp_or)
{
    int condi = 0;
    for (int n = 1; cmd[n] != '\0'; n++) {
        if (cmd[n - 1] == '&' && cmd[n] == '&')
            tmp_and++;
        if (cmd[n - 1] == '|' && cmd[n] == '|')
            tmp_or++;
        if (cmd[n] != '&' && cmd[n] != '|' && cmd[n] != ' ' && cmd[n] != '\t') {
            tmp_or = 0;
            tmp_and = 0;
            condi = 0;
            word++;
        }
        if (condi != 0 && (tmp_and != 0 || tmp_or != 0) && cmd[n] != ' ' &&
            cmd[n] != '\t')
            return write_error_rep("Invalid null command.\n");
        if (tmp_and != 0 || tmp_or != 0)
            condi = 1;
    }
    sub_verif_syntax_and_or(condi, tmp_and, tmp_or);
    return 0;
}

int verif_syntax_and_or_two(char *cmd, int i)
{
    while (i < my_strlen(cmd) && (cmd[i] == ' ' || cmd[i] == '\t'))
        i++;
    if (cmd[i] == '&')
        return 1;
    return 0;
}

int verif_error_and_or(char *cmd, i_s *info_shell)
{
    if (cmd[0] == '|' || cmd[0] == '&') {
        info_shell->return_value = 1;
        return write_error_rep("Invalid null command.\n");
    }
    if (cmd[(my_strlen(cmd) - 1)] == '|' || cmd[(my_strlen(cmd) - 1)] == '&') {
        info_shell->return_value = 1;
        return write_error_rep("Invalid null command.\n");
    } if (verif_simple_and_or(cmd, info_shell) == 1 ||
    verif_syntax_and_or(cmd, 0, 0, 0) == 1)
        return 1;
    int tmp = 0;
    for (int i = 0; cmd[i] != '\0'; i++) {
        if ((cmd[i] == '&' && cmd[i + 1] == '&') || (cmd[i] == '|' &&
            cmd[i + 1] == '|'))
            tmp = verif_syntax_and_or_two(cmd, (i + 2));
        if (tmp == 1) {
            info_shell->return_value = 1;
            return write_error_rep("Invalid null command.\n");
        }
    } return 0;
}
