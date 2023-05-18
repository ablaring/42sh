/*
** EPITECH PROJECT, 2022
** fleche_left.c
** File description:
** Function : fleche_left
*/

#include "struct_all.h"
#include "my.h"

void flech_left(i_s *info_shell)
{
    info_shell->st_edit.size_term = get_size_term();
    if ((info_shell->st_edit.pos_in_cmd + 13) %
        ((info_shell->st_edit.size_term)) != 0)
        mini_printf("\b");
    else {
        for (int n = 1; n < info_shell->st_edit.size_term; n++)
            mini_printf("\x1B[1C");
        mini_printf("\033[1A");
    }
    info_shell->st_edit.pos_in_cmd--;
}
