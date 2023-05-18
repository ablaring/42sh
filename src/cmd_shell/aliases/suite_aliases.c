/*
** EPITECH PROJECT, 2022
** shell.c
** File description:
** Function : shell
*/

#include "struct_all.h"
#include "my.h"

int print_alias_one_arg(i_s *info_shell, char **temp)
{
    strcat(temp[1], " ");
    for (int i = 0; i != info_shell->nb_alias; i++){
        if (strcmp(temp[1], info_shell->alias[i].name) == 0){
            mini_printf("%s\n", info_shell->alias[i].cmd);
            return 0;
        }
    }
    return 0;
}

void find_alias(i_s *info_shell, char *cmd, char *one_arg)
{
    char **temp = my_str_to_word_array(cmd, " ");
    int nb = count_double_arr(temp);
    if (strcmp(one_arg, "alias ") != 0 || nb == 1)
        return;
    int i = 0;
    for (; i != info_shell->nb_alias; i++)
        if (strcmp(temp[1], info_shell->alias[i].name) == 0)
            mini_printf("%s\n", info_shell->alias[i].cmd);
}

char *cut_str(char *str)
{
    char *new_str = malloc(sizeof(char) * (my_strlen(str) + 1));
    int i = 1;
    int j = 0;
    for (; str[i] != '"'; i++);
    i++;
    for (; str[i] != '\0' && str[i] != '"'; i++, j++)
        new_str[j] = str[i];
    new_str[j] = '\0';
    return new_str;
}

int find_same_allias(i_s *info_shell, char *temp, char *temp2)
{
    int nb = 0;
    if (info_shell->alias == NULL)
        return 1;
    for (size_t i = 0; info_shell->alias[i].name != NULL; i++) {
        if (strcmp(temp, info_shell->alias[i].name) == 0){
            info_shell->alias[i].cmd = my_strdup(temp2);
            nb = 1;
        }
    }
    if (nb == 0)
        return 1;
    info_shell->alias[info_shell->nb_alias].name = NULL;
    info_shell->alias[info_shell->nb_alias].cmd = NULL;
    return 0;
}

void my_alias_end(i_s *info_shell, char *temp_sec)
{
    strcat(temp_sec, "\0");
    fill_alias_end(info_shell, temp_sec);
    info_shell->nb_alias++;
    info_shell->alias[info_shell->nb_alias].name = NULL;
    info_shell->alias[info_shell->nb_alias].cmd = NULL;
}
