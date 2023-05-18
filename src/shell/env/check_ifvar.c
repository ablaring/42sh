/*
** EPITECH PROJECT, 2022
** all_cleaner.c
** File description:
** Function : all_cleaner
*/

#include "struct_all.h"
#include "my.h"

void print_undefined_var(char *temp)
{
    for (size_t i = 1; temp[i] != '\0'; i++){
        mini_printf("%c", temp[i]);
    }
}

int if_arg_variable_env_suite(i_s *info_shell, char **temp, int k)
{
    for (int j = 0; info_shell->env_loc[j].name != NULL; j++)
        if (strcmp(info_shell->env_loc[j].name, temp[k]) == 0){
            temp[k] = strdup(info_shell->env_loc[j].cmd);
            return 0;
        }
    print_undefined_var(temp[k]);
    my_putstr(": Undefined variable.\n");
    return 1;
}

int check_if_varenv(char *cmd)
{
    int i = 0;
    for (; cmd[i] != '\0'; i++)
        if (cmd[i] == '$' && cmd[i + 1] != '\0' && cmd[i + 1] != ' '){
            return 1;
    }
    return 0;
}
