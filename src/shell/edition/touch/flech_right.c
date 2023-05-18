/*
** EPITECH PROJECT, 2022
** flech_right.c
** File description:
** Function : flech_right
*/

#include "struct_all.h"
#include "my.h"

void flech_right(i_s *info_shell)
{
    info_shell->st_edit.size_term = get_size_term();
    if ((info_shell->st_edit.pos_in_cmd + 14) %
        ((info_shell->st_edit.size_term)) != 0)
        mini_printf("\033[1C");
    else {
        mini_printf("\x1B[B");
        for (int n = 1; n < info_shell->st_edit.size_term; n++)
            mini_printf("\x1B[2D");
    }
    info_shell->st_edit.pos_in_cmd++;
}
