/*
** EPITECH PROJECT, 2022
** all_cleaner.c
** File description:
** Function : all_cleaner
*/

#include "struct_all.h"
#include "my.h"

void find_home(i_s *info_shell)
{
    int j = 0;
    for (; info_shell->env_loc[j].name != NULL; j++)
        if (strcmp(info_shell->env_loc[j].name, "$HOME") == 0){
            info_shell->home = strdup(info_shell->env_loc[j].cmd);
            break;
        }
}

int error_env_fill(i_s *info_shell, int *i, int j)
{
    if (my_letter_isalpha(info_shell->env[*i][j]) == 1 &&
        info_shell->env[*i][j] != '_' && info_shell->env[*i][j] != '='){
        *i += 1;
        return 1;
    }
    return 0;
}

void if_arg_variable_env_sec(char **new_cmd, char **temp, int tail)
{
    int k = 0;
    free(*new_cmd);
    *new_cmd = calloc(tail + 2, sizeof(char));
    for (k = 0; temp[k] != NULL; k++){
        strcat(*new_cmd, temp[k]);
        if (temp[k + 1] != NULL)
            strcat(*new_cmd, " ");
    }
}

void stock_setenv_loc(i_s *info_shell, char **tab_cmd)
{
    info_shell->env_loc[info_shell->nb_env].name =
    malloc(sizeof(char) * (my_strlen(tab_cmd[1]) + 2));
    info_shell->env_loc[info_shell->nb_env].name[0] = '$';
    info_shell->env_loc[info_shell->nb_env].name[1] = '\0';
    strcat(info_shell->env_loc[info_shell->nb_env].name, tab_cmd[1]);
    info_shell->env_loc[info_shell->nb_env].cmd = strdup(tab_cmd[2]);
    info_shell->nb_env++;
    info_shell->env_loc[info_shell->nb_env].name = NULL;
    info_shell->env_loc[info_shell->nb_env].cmd = NULL;
}

int if_arg_variable_env(i_s *info_shell, char *cmd, char **new_cmd)
{
    int k = 0;
    int nb_return = 0;
    int tail = 0;
    char **temp = my_str_to_word_array(cmd, " ");
    for (; temp[k] != NULL; k++){
        if (strcmp(temp[k], "$?") == 0)
            temp[k] = my_itoa(info_shell->return_value);
        if (temp[k][0] == '$' && temp[k][1] != '\0' && temp[k][1] != '?'){
            nb_return =
            if_arg_variable_env_suite(info_shell, temp, k);
            tail += my_strlen(temp[k]) + 2;
        }
    }
    tail += my_strlen(cmd);
    if_arg_variable_env_sec(new_cmd, temp, tail);
    return nb_return;
}
