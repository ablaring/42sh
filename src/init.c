/*
** EPITECH PROJECT, 2022
** init.c
** File description:
** Function : init_all
*/

#include "struct_all.h"
#include "my.h"


void init_redi(i_s *info_shell)
{
    info_shell->st_redi.pipe_out = malloc(sizeof(int) * 4);
    info_shell->st_redi.redir_type = malloc(sizeof(int) * 6);
    info_shell->st_redi.redir_type[0] = 0;
    info_shell->st_redi.redir_type[1] = 0;
    info_shell->st_redi.redir_type[2] = 0;
    info_shell->st_redi.redir_type[3] = 0;
    info_shell->st_redi.redir_type[4] = -2;
    info_shell->st_redi.redir_file_in = malloc(sizeof(char) * 4);
    info_shell->st_redi.redir_file_in[0] = '#';
    info_shell->st_redi.redir_file_in[1] = '8';
    info_shell->st_redi.redir_file_in[2] = '#';
    info_shell->st_redi.redir_file_in[3] = '\0';
    info_shell->st_redi.redir_file_out = malloc(sizeof(char) * 4);
    info_shell->st_redi.redir_file_out[0] = '#';
    info_shell->st_redi.redir_file_out[1] = '8';
    info_shell->st_redi.redir_file_out[2] = '#';
    info_shell->st_redi.redir_file_out[3] = '\0';
}

void init_basic_pipe(i_s *info_shell)
{
    info_shell->st_pipe.nb_pipe = 0;
    info_shell->st_pipe.pos = 0;
    info_shell->is_true = malloc(sizeof(i_s) * 25);
}

void init_basic_struct(i_s *info_shell, char **env)
{
    int size = 0;
    for (; env[size] != NULL; size++);
    info_shell->env = malloc(sizeof(char *) * (size + 5));
    for (int n = 0; n < size; n++) {
        info_shell->env[n] = malloc(sizeof(char) * my_strlen(env[n]));
        info_shell->env[n] = env[n];
    }
    if (size == 0) {
        info_shell->env[0] = strdup("PATH=/usr/bin");
        size++;
    }
    info_shell->stop = 0;
    info_shell->restart = 0;
    init_basic_struct_sec(info_shell, size);
}

int init_struct(i_s *info_shell, char **env)
{
    init_basic_struct(info_shell, env);
    info_shell->alias = malloc(sizeof(i_s) * 100);
    info_shell->alias[0].name = NULL;
    init_redi(info_shell);
    init_basic_pipe(info_shell);
    init_history(info_shell);
    init_edition(info_shell);
    stock_variable(info_shell);
    find_home(info_shell);
    init_edition_st();
    return 0;
}
