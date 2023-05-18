/*
** EPITECH PROJECT, 2022
** touch_cmd_edition.c
** File description:
** Function : touch_cmd_edition
*/

#include "struct_all.h"
#include "my.h"

void flech_edition(i_s *info_shell, int ch)
{
    if (ch == 'A')
        flech_up(info_shell);
    if (ch == 'B')
        flech_down(info_shell);
    if (ch == 'C') {
        if ((my_strlen(info_shell->st_edit.list_cmd[
            info_shell->st_edit.pos_history])) >
                info_shell->st_edit.pos_in_cmd)
            flech_right(info_shell);
    }
    if (ch == 'D') {
        if (info_shell->st_edit.pos_in_cmd > 0) {
            flech_left(info_shell);
        }
    }
}
