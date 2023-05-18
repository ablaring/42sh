/*
** EPITECH PROJECT, 2022
** shell.c
** File description:
** Function : shell
*/

#include "struct_all.h"
#include "my.h"

void process_aliases_suite(int *lock, i_s *info_shell, char **tmp, int j)
{
    for (int i = 0; i != info_shell->nb_alias; i++)
        if (strcmp(tmp[j], info_shell->alias[i].name) == 0) {
            replace_tmp(&tmp[j], info_shell->alias[i].cmd);
            *lock = 1;
        }
}

void fill_alias_debut(i_s *info_shell, char *temp)
{
    info_shell->alias[info_shell->nb_alias].name =
    calloc(my_strlen(temp) + 3, sizeof(char));
    strcat(info_shell->alias[info_shell->nb_alias].name, temp);
    strcat(info_shell->alias[info_shell->nb_alias].name, " \0");
}

void fill_alias_end(i_s *info_shell, char *temp)
{
    info_shell->alias[info_shell->nb_alias].cmd =
    malloc(sizeof(char) * my_strlen(temp));
    info_shell->alias[info_shell->nb_alias].cmd = strdup(temp);
}

int print_alias(i_s *info_shell)
{
    for (int i = 0; i < info_shell->nb_alias; i++){
        for (size_t j = 0; info_shell->alias[i].name[j + 1] != '\0'; j++)
            mini_printf("%c", info_shell->alias[i].name[j]);
        mini_printf(" %s\n",info_shell->alias[i].cmd);
    }
    return 0;
}

int my_alias(i_s *info_shell, char *cmd)
{
    char **temp = my_str_to_word_array(cmd, " ");
    char *temp_sec = calloc(my_strlen(cmd) + 1, sizeof(char));
    int nb = count_double_arr(temp);
    if (nb == 1)
        return print_alias(info_shell);
    if (nb == 2)
        return print_alias_one_arg(info_shell, temp);
    if (nb < 3)
        return 1;
    if (find_same_allias(info_shell, temp[1], temp[2]) == 0)
        return 0;
    fill_alias_debut(info_shell, temp[1]);
    for (size_t i = 2; temp[i] != NULL; i++){
        strcat(temp_sec, temp[i]);
        if (temp[i + 1] != NULL)
            strcat(temp_sec, " ");
    }
    my_alias_end(info_shell, temp_sec);
    return 0;
}
