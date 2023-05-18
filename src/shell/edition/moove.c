/*
** EPITECH PROJECT, 2022
** display_term.c
** File description:
** Function : *
*/

#include "struct_all.h"
#include "my.h"

void moove_right(i_s *info_shell)
{
    info_shell->st_edit.size_term = get_size_term();
    if (((info_shell->st_edit.pos_in_cmd + 14) %
        (info_shell->st_edit.size_term)) != 0) {
        mini_printf("\033[1C");
    } else {
        mini_printf("\x1B[B");
        for (int n = 1; n < info_shell->st_edit.size_term; n++)
            mini_printf("\x1B[2D");
    }
}

void moove_left(i_s *info_shell)
{
    info_shell->st_edit.size_term = get_size_term();

    if (((info_shell->st_edit.pos_in_cmd + 13) %
        (info_shell->st_edit.size_term)) != 0)
        mini_printf("\b");
    else {
        for (int n = 0; n < info_shell->st_edit.size_term; n++)
            mini_printf("\x1B[1C");
        mini_printf("\033[1A");
    }
}
