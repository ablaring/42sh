/*
** EPITECH PROJECT, 2022
** shell.c
** File description:
** Function : shell
*/

#include "struct_all.h"
#include "my.h"

int is_executable(char *filename)
{
    struct stat buffer;
    if (stat(filename, &buffer) != 0)
        return 0;
    return (buffer.st_mode & S_IXUSR) ||
    (buffer.st_mode & S_IXGRP) || (buffer.st_mode & S_IXOTH);
}

int where_sec(char *temp)
{
    char *path = getenv("PATH");
    if (!path)
        return 1;
    char *path_copy = strdup(path);
    char *dir = strtok(path_copy, ":");
    int found = 0;
    while (dir) {
        char full_path[1024];
        snprintf(full_path, sizeof(full_path), "%s/%s", dir, temp);
        if (is_executable(full_path)) {
            mini_printf("%s\n", full_path);
            found = 1;
        }
        dir = strtok(NULL, ":");
    }
    if (!found)
        return 1;
    free(path_copy);
    return 0;
}

void sub_where_alias(i_s *info_shell, int i, char *temp2)
{
    if (info_shell->st_pipe.nb_pipe == 0)
        mini_printf("%s is aliased to %s\n",
            temp2, info_shell->alias[i].cmd);
    else
        dprintf(info_shell->st_pipe.pi[info_shell->st_pipe.pos][1],
            "%s is aliased to %s\n", temp2, info_shell->alias[i].cmd);
}

int where_alias(i_s *info_shell, char *temp)
{
    int i = 0;
    int nb = 1;
    char *temp2 = strdup(temp);
    temp2[my_strlen(temp2)] = '\0';
    for (; i != info_shell->nb_alias; i++) {
        if (my_strcmp(temp, info_shell->alias[i].name) == 0) {
            sub_where_alias(info_shell, i, temp2);
            nb = 0;
        }
    }
    free(temp2);
    if (nb == 0)
        return 0;
    return 1;
}

int where(i_s *info_shell, char *cmd)
{
    char **temp = my_str_to_word_array(cmd, " ");
    int nb_arr = count_double_arr(temp);
    int nb_return = 0;
    if (nb_arr < 2) {
        info_shell->return_value = 1;
        if (info_shell->st_pipe.nb_pipe == 0)
            write_error("where: Too few arguments.\n");
        else
            dprintf(info_shell->st_pipe.pi[info_shell->st_pipe.pos][1],
                "where: Too few arguments.\n");
        return 1;
    } for (size_t i = 0; temp[1][i] != '\0'; i++) {
        if (verif_where(temp, i, info_shell) == 1)
            return (1);
    }
    nb_return = where_end(info_shell, temp, nb_arr, nb_return);
    return nb_return;
}
