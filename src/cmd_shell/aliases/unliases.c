/*
** EPITECH PROJECT, 2022
** shell.c
** File description:
** Function : shell
*/

#include "struct_all.h"
#include "my.h"

void find_unalias_arg(i_s *info_shell, char *temp, int i, int *k)
{
    if (strcmp(temp, info_shell->alias[i].name) == 0){
        info_shell->to_sup_unalias[*k] = strdup(info_shell->alias[i].name);
        *k += 1;
    }
}

void init_new_alias(i_s *info_shell)
{
    info_shell->new_alias = malloc(sizeof(i_s) * 100);
    for (int i = 0; i < 100; ++i) {
        info_shell->new_alias[i].name = NULL;
        info_shell->new_alias[i].cmd = NULL;
    }
}

void cp_new_alias(i_s *info_shell)
{
    free(info_shell->alias);
    info_shell->alias = malloc(sizeof(i_s) * 100);
    info_shell->nb_alias = 0;
    for (size_t i = 0; info_shell->new_alias[i].name != NULL; i++){
        info_shell->alias[i].name = strdup(info_shell->new_alias[i].name);
        info_shell->alias[i].cmd = strdup(info_shell->new_alias[i].cmd);
        info_shell->nb_alias++;
    }
}

void new_alias(i_s *info_shell)
{
    int k = 0;
    init_new_alias(info_shell);
    for (size_t i = 0; info_shell->to_sup_unalias[i] != NULL; i++)
        if (strcmp(info_shell->to_sup_unalias[i],
        info_shell->alias[i].name) != 0){
            info_shell->new_alias[k].name = strdup(info_shell->alias[i].name);
            info_shell->new_alias[k].cmd = strdup(info_shell->alias[i].cmd);
            k++;
        }
    cp_new_alias(info_shell);
}

int my_unalias(i_s *info_shell, char *cmd)
{
    char **temp = my_str_to_word_array(cmd, " ");
    int nb = count_double_arr(temp);
    int k = 0;
    if (nb == 1 && info_shell->st_pipe.nb_pipe == 0){
        write_error("unalias: Too few arguments.\n");
        return 1;
    }else if (info_shell->st_pipe.nb_pipe != 0)
        dprintf(info_shell->st_pipe.pi[info_shell->st_pipe.pos][1],
        "unalias: Too few arguments.\n");
    info_shell->to_sup_unalias = malloc(sizeof(char) * 100);
    for (size_t i = 0; info_shell->alias[i].name != NULL; i++)
        for (size_t j = 0; temp[j] != NULL; j++){
            strcat(temp[j], " ");
            find_unalias_arg(info_shell, temp[j], i, &k);
        }
    info_shell->to_sup_unalias[k] = NULL;
    if (k == 0)
        return 1;
    new_alias(info_shell);
    return 0;
}
