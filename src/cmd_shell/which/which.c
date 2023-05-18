/*
** EPITECH PROJECT, 2022
** which.c
** File description:
** Function : shell
*/

#include "struct_all.h"
#include "my.h"

void sub_wich_alias(i_s *info_shell, char *temp2, int i)
{
    if (info_shell->st_pipe.nb_pipe == 0)
        dprintf(2, "%s:          aliased to %s\n",
            temp2, info_shell->alias[i].cmd);
    else
        dprintf(info_shell->st_pipe.pi[info_shell->st_pipe.pos][1],
            "%s:          aliased to %s\n", temp2,
                info_shell->alias[i].cmd);
}

int which_alias(i_s *info_shell, char *temp)
{
    int i = 0;
    int nb = 1;
    char *temp2 = strdup(temp);
    temp2[my_strlen(temp2)] = '\0';
    for (; i != info_shell->nb_alias; i++)
        if (my_strcmp(temp, info_shell->alias[i].name) == 0) {
            sub_wich_alias(info_shell, temp2, i);
            nb = 0;
        }
    free(temp2);
    if (nb == 0)
        return 0;
    return 1;
}

int which_sec(char *temp)
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
            return 0;
        }
        dir = strtok(NULL, ":");
    }
    if (!found)
        return 1;
    free(path_copy);
    return 0;
}

void wich_end(i_s *info_shell, int *nb, char *temp, int *nb_return)
{
    if (is_builtin_cmd(temp) == 0){
        mini_printf("%s: shell built-in command.\n", temp);
        *nb = 1;
    }
    if (*nb == 0 && which_alias(info_shell, temp) == 1 &&
        which_sec(temp) == 1) {
        printf("%s: Command not found.\n", temp);
        info_shell->return_value = 1;
        *nb_return = 1;
    }
    *nb = 0;
}

int which(i_s *info_shell, char *cmd)
{
    char **temp = my_str_to_word_array(cmd, " ");
    int nb_arr = count_double_arr(temp);
    int nb_return = 0;
    int nb = 0;
    if (nb_arr < 2) {
        my_putstr("which: Too few arguments.\n");
        info_shell->return_value = 1;
        return 1;
    }
    for (int i = 1; i < nb_arr; i++)
        wich_end(info_shell, &nb, temp[i], &nb_return);
    return nb_return;
}
