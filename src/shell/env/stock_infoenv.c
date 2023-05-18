/*
** EPITECH PROJECT, 2022
** all_cleaner.c
** File description:
** Function : all_cleaner
*/

#include "struct_all.h"
#include "my.h"

void fill_env_cmd(i_s *info_shell, int j, char *word, int *k)
{
    char *temp = malloc(sizeof(char) * my_strlen(word) * 3);
    size_t i = 0;
    j += 1;
    for (; word[j] != '\0'; i++, j++)
        temp[i] = word[j];
    temp[i] = '\0';
    info_shell->env_loc[*k].cmd = strdup(temp);
    free(temp);
}

void process_env(i_s *info_shell, int *i, int *k, char *temp)
{
    int j = 0;
    for (; info_shell->env[*i][j] != '\0'; j++) {
        if (my_letter_isalpha(info_shell->env[*i][j]) == 0 ||
            info_shell->env[*i][j] == '_')
            temp[j] = info_shell->env[*i][j];
        if (info_shell->env[*i][j] == '=') {
            temp[j] = '\0';
            break;
        }
        if (error_env_fill(info_shell, i, j) == 1)
            return;
    }
    fill_name_and_cmd(info_shell, i, k, temp);
}

void fill_name_and_cmd(i_s *info_shell, int *i, int *k, char *temp)
{
    int j = my_strlen(temp);
    info_shell->env_loc[*k].name = malloc(sizeof(char) * (my_strlen(temp) + 2));
    info_shell->env_loc[*k].name[0] = '$';
    info_shell->env_loc[*k].name[1] = '\0';
    strcat(info_shell->env_loc[*k].name, temp);
    fill_env_cmd(info_shell, j, info_shell->env[*i], k);
    if (info_shell->env[*i + 1])
        *k += 1;
    free(temp);
}

void check_if_variable(i_s *info_shell, int *i, int *k)
{
    if (!info_shell->env[*i])
        return;
    char *temp = malloc(sizeof(char) * my_strlen(info_shell->env[*i]) + 1);
    process_env(info_shell, i, k, temp);
}

void stock_variable(i_s *info_shell)
{
    info_shell->env_loc = malloc(sizeof(env_s) * 10000);
    int k = 0;
    for (int i = 1; info_shell->env[i - 1]; i++)
        check_if_variable(info_shell, &i, &k);
    info_shell->env_loc[k + 1].name = NULL;
    info_shell->env_loc[k + 1].cmd = NULL;
}
