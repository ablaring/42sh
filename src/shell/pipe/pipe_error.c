/*
** EPITECH PROJECT, 2022
** main_pipe.c
** File description:
** Function : main_pipe
*/

#include "struct_all.h"
#include "my.h"

int error_pipe(char *cmd, i_s *info_shell)
{
    for (int j = 0; cmd[j] != '\0'; j++)
        if (cmd[j] == '|' && cmd[j + 1] == ' ' && cmd[j + 2] == '|') {
            write_error_rep("Invalid null command.\n");
            return info_shell->return_value = 1;
        }
    return 0;
}
