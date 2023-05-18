/*
** EPITECH PROJECT, 2022
** backticks.c
** File description:
** Function : all_cleaner
*/

#include "struct_all.h"
#include "my.h"

char *strdup_between(char *str, int start, int end)
{
    char *new_str = malloc(sizeof(char) * (end - start + 2));
    int i = 0;
    for (int n = start; n <= end; n++) {
        new_str[i] = str[n];
        i++;
    }
    new_str[i] = '\0';
    return new_str;
}

char *cleaner_backsticks2(char *tab_cmd)
{
    int nb_backsticks = 0;
    int k = 0;
    int t = 0;
    for (size_t i = 0; tab_cmd[i] != '\0'; i++){
        if (tab_cmd[i] == '\'' && nb_backsticks == 0)
            k = i;
        if (tab_cmd[i] == '\'')
            nb_backsticks++;
        if (nb_backsticks == 2){
            nb_backsticks = 0;
            tab_cmd[k] = ' ';
            tab_cmd[i] = ' ';
            t++;
        }
    }
    return tab_cmd;
}

char *cleaner_backsticks(char *tab_cmd)
{
    int nb_backsticks = 0;
    int k = 0;
    int t = 0;
    tab_cmd = cleaner_backsticks2(tab_cmd);
    for (size_t i = 0; tab_cmd[i] != '\0'; i++){
        if (tab_cmd[i] == '"' && nb_backsticks == 0)
            k = i;
        if (tab_cmd[i] == '"')
            nb_backsticks++;
        if (nb_backsticks == 2){
            nb_backsticks = 0;
            tab_cmd[k] = ' ';
            tab_cmd[i] = ' ';
            t++;
        }
    }
    return tab_cmd;
}

char *cleaner_parentheses(char *tab_cmd)
{
    int nb_backsticks = 0;
    int k = 0;
    for (size_t i = 0; tab_cmd[i] != '\0'; i++){
        if (tab_cmd[i] == '(' && nb_backsticks == 0){
            k = i;
            nb_backsticks++;
        }
        if (tab_cmd[i] == ')' && nb_backsticks == 1)
            nb_backsticks++;
        if (nb_backsticks == 2){
            nb_backsticks = 0;
            tab_cmd[k] = ' ';
            tab_cmd[i] = ' ';
            nb_backsticks = 0;
        }
    }
    return tab_cmd;
}
