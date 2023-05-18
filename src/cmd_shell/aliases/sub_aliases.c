/*
** EPITECH PROJECT, 2022
** shell.c
** File description:
** Function : shell
*/

#include "struct_all.h"
#include "my.h"

void process_aliases(char **tmp, i_s *info_shell, int *lock)
{
    int j = 0;
    for (; tmp[j] != NULL; j++) {
        adjust_tmp(&tmp[j]);
        process_aliases_suite(lock, info_shell, tmp, j);
    }
    tmp[j] = NULL;
}

void adjust_tmp(char **tmp_j)
{
    char *temp = realloc(*tmp_j, strlen(*tmp_j) + 2);
    if (temp != NULL) {
        *tmp_j = temp;
        strcat(*tmp_j, " ");
    }
}

void replace_tmp(char **tmp_j, char *cmd)
{
    char *new_str = strdup(cmd);
    if (new_str != NULL) {
        free(*tmp_j);
        *tmp_j = new_str;
    }
}

void update_cmd(char **one_arg, char **cmd, char **tmp)
{
    free(*one_arg);
    free(*cmd);
    *cmd = malloc(sizeof(char) * (5000));
    if (*cmd != NULL) {
        (*cmd)[0] = '\0';
    }
    for (int i = 0; tmp[i] != NULL; i++) {
        strcat(*cmd, tmp[i]);
        if (tmp[i + 1] != NULL)
            strcat(*cmd, " ");
    }
    *one_arg = one_word(*cmd);
}

void check_allias(char **one_arg, char **cmd, i_s *info_shell)
{
    find_alias(info_shell, *cmd, *one_arg);
    char **tmp = my_str_to_word_array(*cmd, " ");
    int lock = 0;
    process_aliases(tmp, info_shell, &lock);
    if (lock != 0)
        update_cmd(one_arg, cmd, tmp);
}
