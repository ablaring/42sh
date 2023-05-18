/*
** EPITECH PROJECT, 2022
** reset_init_edition.c
** File description:
** Function : *
*/

#include "struct_all.h"
#include "my.h"

void init_edition(i_s *info_shell)
{
    info_shell->st_edit.list_cmd = malloc(sizeof(char *) * 254);
    info_shell->st_edit.tmp_display_tab = malloc(sizeof(char *) * 254);
    for (int n = 0; n < 253; n++) {
        info_shell->st_edit.list_cmd[n] = malloc(sizeof(char) * 2050);
        memset(info_shell->st_edit.list_cmd[n], 0, 2049);
    }
    info_shell->st_edit.tmp_tab = malloc(sizeof(char) * 2054);
    memset(info_shell->st_edit.tmp_tab, 0, 2050);
    info_shell->st_edit.tmp_find_cmd = malloc(sizeof(char) * 2050);
    info_shell->st_edit.hour = malloc(sizeof(int) * 254);
    info_shell->st_edit.minute = malloc(sizeof(int) * 254);
    info_shell->st_edit.not_start_cmd = 0;
}

void reset_struct_edition(i_s *info_shell)
{
    for (int n = 0; n < 250; n++)
        memset(info_shell->st_edit.list_cmd[n], 0, 2047);
    info_shell->st_edit.size_list_cmd = info_shell->st_edit.size_history;
    info_shell->st_edit.pos_history = 0;
    info_shell->st_edit.pos_in_cmd = 0;
    for (int n = 0; n < info_shell->st_edit.size_history; n++)
        my_strcpy(info_shell->st_edit.list_cmd[n + 1],
            info_shell->st_edit.history[n]);
    info_shell->st_edit.size_last_cmd = 0;
    info_shell->st_edit.nb_back = 0;
    info_shell->st_edit.size_term = get_size_term();
    info_shell->st_edit.pos_in_cmd = 0;
    info_shell->st_edit.reset = 0;
    info_shell->st_edit.size_tmp_display_tab = 0;
}
