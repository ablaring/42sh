/*
** EPITECH PROJECT, 2022
** shell.c
** File description:
** Function : shell
*/

#include "struct_all.h"
#include "my.h"

int check_backsicks(char *cmd)
{
    int nb_backsticks = 0;
    for (size_t i = 0; cmd[i] != '\0'; i++){
        if (cmd[i] == '`')
            nb_backsticks++;
        if (nb_backsticks == 2){
            nb_backsticks = 0;
            return 0;
        }
    }
    return 1;
}
