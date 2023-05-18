/*
** EPITECH PROJECT, 2022
** redirect_error_suite.c
** File description:
** redirect_error_suite.c
*/

#include "struct_all.h"
#include "my.h"

int suite_suite_rep_error(char *cmd, i_s *info_shell, int n)
{
    if (cmd[n] == '<') {
        if (cmd[n + 1] == '>') {
            info_shell->return_value = 1;
            return write_error_rep("Missing name for redirect.\n");
        } if (my_strlen(cmd) > (n + 2) && cmd[n + 1] == '<' &&
            cmd[n + 2] == '<') {
            info_shell->return_value = 1;
            return write_error_rep("Missing name for redirect.\n");
        } if (my_strlen(cmd) > (n + 2) && cmd[n + 1] == ' ' &&
            (cmd[n + 2] == '>' || cmd[n + 2] == '<')) {
            info_shell->return_value = 1;
            return write_error_rep("Missing name for redirect.\n");
        }
    }
    return 0;
}
