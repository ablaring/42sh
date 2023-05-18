/*
** EPITECH PROJECT, 2022
** my_cd.c
** File description:
** Function : cd
*/

#include "struct_all.h"
#include "my.h"

int verif_arg_cd(char *arg)
{
    if (my_strlen(arg) >= 3 && arg[3] == '-' && arg[4] == '\0')
        return -1;
    int nb = 0;
    for (int n = 0; arg[n] != '\0'; arg++) {
        if (arg[n] == ' ')
            nb++;
    }
    return nb;
}

int error_my_cd(i_s *info_shell)
{
    if (info_shell->back_dir[0] == 'n' && info_shell->back_dir[1] == 'o' &&
        info_shell->back_dir[2] == '\0'){
        if (info_shell->st_pipe.nb_pipe == 0)
            write_error(": No such file or directory.\n");
        else
            dprintf(info_shell->st_pipe.pi[info_shell->st_pipe.pos][1],
                ": No such file or directory.\n");
        return info_shell->return_value = 1;
    } if (chdir(info_shell->back_dir) == -1) {
        if (info_shell->st_pipe.nb_pipe == 0)
            write_error("Error command: \'cd -\'\n");
        else
            dprintf(info_shell->st_pipe.pi[info_shell->st_pipe.pos][1],
                "Error command: \'cd -\'\n");
        return info_shell->return_value = 1;
    }
    getcwd(info_shell->back_dir, 256);
    return 0;
}

int my_cd(i_s *info_shell, char *cmd)
{
    info_shell->st_cond.cmd_good = 1;
    int error = verif_arg_cd(cmd);
    if (error != -1 && error != 0 && error != 1) {
        if (info_shell->st_pipe.nb_pipe == 0)
            write_error("cd: Too many arguments\n");
        else
            dprintf(info_shell->st_pipe.pi[info_shell->st_pipe.pos][1],
                "cd: Too many arguments\n");
        return info_shell->return_value = 1;
    }
    my_cd_error_home(info_shell, error);
    if (error == 1) {
        if (error_is_one(info_shell, cmd) == 0)
            return (0);
    }
    if (error == -1)
        return (error_my_cd(info_shell));
    return info_shell->return_value;
}
