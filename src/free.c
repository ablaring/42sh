/*
** EPITECH PROJECT, 2022
** free.c
** File description:
** Function: free_struct
*/

#include "struct_all.h"
#include "my.h"

void free_struct(i_s *info_shell)
{
    free(info_shell->env);
    free(info_shell->dir);
    free(info_shell->back_dir);
    for (int n = 0; n < 253; n++) {
        free(info_shell->st_edit.history[n]);
        free(info_shell->st_edit.list_cmd[n]);
    }
}
