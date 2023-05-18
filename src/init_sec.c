/*
** EPITECH PROJECT, 2022
** init.c
** File description:
** Function : init_all
*/

#include "struct_all.h"
#include "my.h"

void init_basic_struct_sec(i_s *info_shell, int size)
{
    info_shell->dir = malloc(sizeof(char) * 256);
    getcwd(info_shell->dir, 256);
    info_shell->back_dir = malloc(sizeof(char) * 257);
    info_shell->back_dir[0] = 'n';
    info_shell->back_dir[1] = 'o';
    info_shell->back_dir[2] = '\0';
    info_shell->size_env = size;
    info_shell->env[size] = NULL;
    info_shell->exit_value = 0;
    info_shell->return_value = 0;
    info_shell->nb_alias = 0;
}
