/*
** EPITECH PROJECT, 2023
** my_cd2.c
** File description:
** my_cd2.c
*/

#include "struct_all.h"
#include "my.h"

int change_dir(i_s *info_shell, char *arg)
{
    getcwd(info_shell->back_dir, 256);
    if (chdir(arg) == -1) {
        if (info_shell->st_pipe.nb_pipe == 0)
            double_write(arg, ": No such file or directory.\n");
        else
            dprintf(info_shell->st_pipe.pi[info_shell->st_pipe.pos][1],
                "%s: No such file or directory.\n", arg);
        return info_shell->return_value = 1;
    }
    getcwd(info_shell->dir, 256);
    return 0;
}

static char *good_arg(i_s *info_shell, char *arg)
{
    int dep = 0;
    for (; arg[dep] != ' ' && arg[dep] != '\0'; dep++);
    int size = 0;
    for (int n = dep; arg[n]; n++)
        size++;
    char *result = malloc(sizeof(char) * (size + 2));
    dep++;
    int a = 0;
    for (; arg[dep] != '\0'; dep++) {
        result[a] = arg[dep];
        if (result[a] == '\n') {
            result[a] = '\0';
            break;
        }
        a++;
    } result[a] = '\0';
    free(arg);
    my_strcpy(info_shell->back_dir, result);
    return result;
}

void sub_error_home(i_s *info_shell)
{
    if (info_shell->st_pipe.nb_pipe == 0)
        write_error("cd: Error Home\n");
    else
        dprintf(info_shell->st_pipe.pi[info_shell->st_pipe.pos][1],
            "cd: Error Home\n");
}

void my_cd_error_home(i_s *info_shell, int error)
{
    error == 0 ? (
        chdir(info_shell->home) == -1 ?
            (info_shell->st_pipe.nb_pipe == 0 ?
                write_error("cd: Error Home\n") :
                dprintf(info_shell->st_pipe.pi[info_shell->st_pipe.pos][1],
                "cd: Error Home\n")
            ) :
            (void)0,
        info_shell->return_value = 0,
        getcwd(info_shell->dir, 256)
    ) :
    (void)0;
}

int error_is_one(i_s *info_shell, char *cmd)
{
    char *go_directo = good_arg(info_shell, cmd);
    int error_perm = verif_perm_directo(go_directo);
    if (error_perm == 1)
        return 0;
    info_shell->return_value = 0;
    change_dir(info_shell, go_directo);
    return (1);
}
