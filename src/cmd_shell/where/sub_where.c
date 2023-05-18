/*
** EPITECH PROJECT, 2023
** sub
** File description:
** sub
*/

#include "struct_all.h"
#include "my.h"

int where_end(i_s *info_shell, char **temp, int nb_arr, int nb_return)
{
    for (int i = 1; i < nb_arr; i++){
        if (is_builtin_cmd(temp[i]) == 0)
            mini_printf("%s is a shell built-in\n", temp[i]);
        if (where_alias(info_shell, temp[i]) == 1 &&
        where_sec(temp[i]) == 1)
            nb_return = 1;
    }
    return nb_return;
}

int is_builtin_cmd(char *temp)
{
    char* builtins[] = {"cd", "exit", "help", "history", NULL};

    for (int i = 0; builtins[i] != NULL; i++)
        if (strcmp(temp, builtins[i]) == 0)
            return 0;

    return 1;
}

int verif_where(char **temp, int i, i_s *info_shell)
{
    if (temp[1][i] == '/'){
        if (info_shell->st_pipe.nb_pipe == 0)
            write_error("where: / in command makes no sense\n");
        else
            dprintf(info_shell->st_pipe.pi[info_shell->st_pipe.pos][1],
                "where: / in command makes no sense\n");
        return 1;
    }
    return (0);
}
