/*
** EPITECH PROJECT, 2022
** home_edition.c
** File description:
** Function : *
*/

#include "struct_all.h"
#include "my.h"

re_s *st_reset;

void init_edition_st(void)
{
    st_reset = malloc(sizeof(re_s));
    st_reset->reset = 0;
}

void sigint_signal_gesture(int sig)
{
    if (sig == SIGINT) {
        mini_printf("\n");
        print_deb();
        st_reset->reset = 1;
    }
    if (sig == SIGTSTP) {
        return;
    }
}

void boucle_get_cmd_edition(i_s *info_shell)
{
    int ch = 0;
    while (ch != EOF) {
        ch = getchar();
        if (st_reset->reset == 1) {
            st_reset->reset = 0;
            reset_struct_edition(info_shell);
            info_shell->restart = 1;
        }
        if (ch == 4) {
            info_shell->st_edit.pos_history = 0;
            my_strcpy(info_shell->st_edit.list_cmd[0], "exit");
            info_shell->stop = 1;
            break;
        }
        if (ch == '\n') {
            break;
        } else {
            create_cmd_edition(info_shell, ch);
        }
    }
}

char *get_cmd_edition(i_s *info_shell)
{
    reset_struct_edition(info_shell);
    st_reset = malloc(sizeof(re_s));
    st_reset->reset = 0;
    struct termios oldattr, newattr;
    tcgetattr(STDIN_FILENO, &oldattr);
    newattr = oldattr;
    newattr.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newattr);
    boucle_get_cmd_edition(info_shell);
    tcsetattr(STDIN_FILENO, TCSANOW, &oldattr);
    mini_printf("\n");
    info_shell->st_edit.list_cmd[
        info_shell->st_edit.pos_history] = change_cmd_history(info_shell,
            info_shell->st_edit.list_cmd[info_shell->st_edit.pos_history]);
    add_cmd_history(info_shell,
        info_shell->st_edit.list_cmd[info_shell->st_edit.pos_history]);
    info_shell->st_edit.list_cmd[info_shell->st_edit.pos_history] =
        cleaner_and_or(info_shell->st_edit.list_cmd[
            info_shell->st_edit.pos_history]);
    return info_shell->st_edit.list_cmd[info_shell->st_edit.pos_history];
}
