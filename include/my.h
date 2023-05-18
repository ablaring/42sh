/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** all prototypes and include
*/

#pragma once

////////////////////////////////////////////////////////////////////////////////
///////////////////////  LIB  //////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

    #include <fcntl.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <sys/stat.h>
    #include <ncurses.h>
    #include <signal.h>
    #include <string.h>
    #include <sys/types.h>
    #include <sys/wait.h>
    #include <dirent.h>
    #include <termios.h>
    #include <sys/ioctl.h>
    #include <ctype.h>
    #include <glob.h>
    #include <time.h>
    #include <fnmatch.h>
    #include <errno.h>

    #include "struct_all.h"
    #include "my.h"

    // Function:
    int mini_printf(const char *format, ...);
    char **read_file(char *av[]);
    int mini_printf(const char *format, ...);
    int printf_credit(int tmp);
    int my_strlen(char const *str);
    char *my_put_nbr_modif(int nb);
    int	my_getnbr(char const *str);
    int my_power(int nb, int p);
    char **my_double_tab(char *buffer, char separator);
    char *patch_separator(char *cmd); // to be used ';' in start string
    int my_strcmp(char const *s1, char const *s2);
    char *my_put_nbr_modif(int nb);
    char *my_put_nbr_double(int nb);
    char *my_revstr(char *str);
    char* my_inv_double_tab(char** txt);
    char* my_inv_double_tab_html(char** txt);
    char *my_strcpy(char *dest, char const *src);
    char **my_str_to_word_array(char *tab, char *sep);
    void fill(char *str, int size);
    char pass_char_wait(int hit, int pos);
    char *my_strcpy(char *dest, char const *src);
    char *my_strupper(char *str);
    int my_strncmp(char const *s1, char const *s2, int n);
    int my_strcmp_p(char const *s1, char const *s2);
    char *my_strdup(const char *str);


////////////////////////////////////////////////////////////////////////////////
///////////////////////  SHELL  ////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

///////////////////////// SHELL ///
    // Shell:
    int shell(i_s *info_shell);
    char *get_cmd(i_s *info_shell);
    int cherch_periph(i_s *info_shell);
    int start_cmd(i_s *info_shell, char *nb_cmd);
    void sub_boucle_shell(void);
    void sub_sub_boucle_shell(i_s *info_shell, char **tab_cmd);
    void error_shell(i_s *info_shell, int nb_error);
    int cherch_nb_dir(char **dir);
    char *my_cleaner(char *cmd);
    int cleaner_and_patch(char *cmd);
    int write_error_setenv(i_s *info_shell, int pos, char *cmd, char **tmp);
    int my_setenv_suite(i_s *info_shell, char *cmd);

    // Function Shell:
    int nb_arg(char *cmd);
    int cherch_nb_dir(char **dir);
    int cherch_in_env(char *env, char *cmd);
    int verif_signal(i_s *info_shell, int pid);
    int verif_perm_directo(char *directo);
    void print_deb(void);
    void sigint_signal_gesture(int sig);
    int verif_espace(char *str);
    void reset_redirect(i_s *info_shell);
    char *one_word(char *cmd);
    char *err_one_word(char *cmd);

    // Function 'OR' and 'AND':
    char *cleaner_and_or(char *cmd);
    int and_or(i_s *info_shell, char *cmd);
    int condition_and_or(i_s *info_shell, char **tab_or_and, int n);
    char **get_cmd_or_and(i_s *info_shell, char *cmd);
    char **get_or_and(i_s *info_shell, char *cmd);
    int verif_error_and_or(char *cmd, i_s *info_shell);

    // Function History:
    void init_history(i_s *info_shell);
    void add_cmd_history(i_s *info_shell, char *cmd);

///////////////////////// EDITION ///

    // Function:
    void init_edition(i_s *info_shell);
    char *patch_echo_appostro(i_s *info_shell, char *cmd);
    char *get_cmd_home(i_s *info_shell);
    void create_cmd_edition(i_s *info_shell, int ch);
    void flech_edition(i_s *info_shell, int ch);
    int get_size_term(void);
    void display_cmd(i_s *info_shell);
    void decale_cara(char* str, int n);
    void deb_cleaner(char *cmd);
    void reset_struct_edition(i_s *info_shell);
    char *get_cmd_edition(i_s *info_shell);
    void back_cursor_delete(i_s *info_shell);
    void sigtstp_handler(int signum);
    char *change_cmd_history(i_s *info_shell, char *tmp);
    char *change_cmd_history_basic(i_s *info_shell, char *tmp);
    char *add_word(char *tmp, const char *str_add, int deb);
    int init_pos_history(i_s *info_shell);
    char *my_itoa(int nb);
    void init_basic_struct_sec(i_s *info_shell, int size);
    bool quotes_right(char *cmd);
    void classic_echo(char *cmd, i_s *info_shell, char **tab);
    char *clean_echo(char *cmd, int nb);
    void sub_get_cmd(char *buffer, int n);
    void init_edition_st(void);

    // Moove:
    void moove_left(i_s *info_shell);
    void moove_right(i_s *info_shell);
    void reset_cursor(i_s *info_shell);

    // Touch:
    void suppr(i_s *info_shell);
    void delete(i_s *info_shell);
    void write_caracter(i_s *info_shell, int ch);
    void flech_left(i_s *info_shell);
    void flech_right(i_s *info_shell);
    void flech_down(i_s *info_shell);
    void flech_up(i_s *info_shell);
        // Tab:
        void home_tab(i_s *info_shell);
        char **get_display_tab(i_s *info_shell);
        void get_tab_cmd(i_s *info_shell);
        int get_tab_is_cmd(i_s *info_shell);
        int find_directory(i_s* info_shell, char* folder_name);
        void display_edition_tab(i_s *info_shell);
        int get_tab_file_in_path(i_s* info_shell, char **files,
            size_t num_files);
        int get_size_max_in_tab(i_s *info_shell);
        void display_cmd_reset_cursor(i_s *info_shell);
        void color_tab_line(i_s *info_shell, int pos);
        void auto_complection(i_s *info_shell);
        int strncmp_position(char *chaine1, char *chaine2, int position);
        int check_chaine_good(char *first_tmp, char *second_tmp, int pos);
        char *get_complection(i_s *info_shell);
        int sub_get_complection(i_s *info_shell, int pos);
        char *get_complection(i_s *info_shell);
        int check_chaine_good(char *first_tmp, char *second_tmp, int pos);
        int strncmp_position(char *chaine1, char *chaine2, int position);

///////////////////////// REDIRECT ///
    // Redirect:
    char *add_space_redirect(char *cmd);
    void redirect_out_double(i_s *info_shell);
    int child_int_single(i_s *info_shell);
    char **redirect_int_double(i_s *info_shell, char* cmd);

    // Fonction Redirect:
    char *get_cmd_redi(i_s *info_shell);
    char **create_tab_cmd(char *cmd, char **arg);
    int start_redirect(i_s *info_shell, char *cmd);
    void stop_redirect(i_s *info_shell);
    int redirect_error(i_s *info_shell, char *cmd);
    int rep_error(char *cmd, i_s *info_shell);
    void add_redir(i_s *info_shell, char *cmd);
    char *redirect_cleaner_cmd(char *cmd);
    int arg_redirect(i_s *info_shell);
    void reset_in(i_s *info_shell);
    int suite_suite_rep_error(char *cmd, i_s *info_shell, int n);

    // Redirect In Single:
    int init_int_single(i_s *info_shell);
    int child_int_single(i_s *info_shell);
    void reset_int_single(i_s *info_shell);
    int redirect_out_single(i_s *info_shell);

    // Redirect Double Single:
    int init_int_double(i_s *info_shell);
    int child_int_double(i_s *info_shell);
    void reset_int_double(i_s *info_shell);
    int init_file_double(i_s *info_shell);
    char **get_out_int_double(i_s *info_shell, char* cmd);

///////////////////////// PIPE ///
    // Pipe:
    int init_pipe(i_s *info_shell);
    int main_pipe(i_s *info_shell, char *cmd);
    int my_other_pipe(i_s *info_shell, char *arg, char *cmd);
    int my_execute_pipe(i_s *info_shell, char *cmd);
    char *redirect_pipe(i_s *info_shell, char *cmd);

    // Utils exc pipe:
    int verif_path_exist(i_s *info_shell);
    char *create_directo(i_s *info_shell, char *access);
    int finish_execute_file(char *cmd, int n_slach, i_s *info_shell);
    int nb_slach(char *cmd);
    char *no_cmd(int size_cmd, char *arg);
    void piped(i_s *info_shell);
    int is_piped(char *cmd);

    // Error Pipe:
    int pipe_error(char *cmd, i_s *info_shell);
    int error_pipe(char *cmd, i_s *info_shell);

    // TMP:
    void all_close_pipe(i_s *info_shell);
    void waitpid_pipe(i_s *info_shell);
    void signal_pipe(i_s *info_shell, pid_t r_fork);

    //globbings
    char ** gestion_all(char **tab_cmd, char *cmd, bool*
    valid, i_s *info_shell);
    bool verif_glob(char * cmd);
    void handle_len_glob(int i, int j, int len, char **tab_tmp);
    void error_handling_glob(char *cmd, int nb_find, char *glob, bool *valid);
    char *cat_cmd(char ** tab_tmp, glob_t globbuf, char *tmp);
    char *gestion_unsetenv_glob(i_s *info_shell, char *cmd);
    int get_lin_glob(char ** tab_tmp);

////////////////////////////////////////////////////////////////////////////////
///////////////////////  COMMAND  //////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

    // Command:
    int my_cd(i_s *info_shell, char *cmd);
    void my_cd_error_home(i_s *info_shell, int error);
    int my_env(i_s *info_shell, char *cmd);
    int my_exit(i_s *info_shell, char *cmd);
    int my_setenv(i_s *info_shell, char *cmd);
    int my_unsetenv(i_s *info_shell, char *cmd);
    int my_other(i_s *info_shell, char *arg, char *cmd);
    int my_pwd(i_s *info_shell, char *cmd);
    int my_execute(i_s *info_shell, char *cmd);
    int my_history(i_s *info_shell, char *cmd);
    int my_echo(i_s *info_shell, char *cmd);
    void verif_term(char **tab, i_s *info_shell, char *cmd);
    void get_term_info(i_s *info_shell);
    int nombre_de_chiffres(int nombre);
    void error_history(i_s *info_shell, int n);
    void displ_hist(i_s *info_shell);
    int error_frmat_history(i_s *info_shell, char *cmd);
    int display_history(i_s *info_shell);
    void supprimer_caractere(i_s *info_shell, char *str, int position);
    void start_cmd_end(i_s *info_shell, char *cmd, char *one_arg);
    char *trim_right(char *s);

    // Function my_other:
    char *cherch_path(i_s *info_shell);
    char *my_other_edit_arg(char *arg);
    char **cherch_dr(i_s *info_shell, char *cmd);
    char *add_cmd(char *path, char *cmd);

    // Command my_setenv && my_unsetenv:
    int new_env(i_s *info_shell, char *arg);
    int edit_env(i_s *info_shell, char **tab_cmd, int nb_arg, int pos_env);
    int cherch_arg_env(i_s *info_shell, char *cmd);


////////////////////////////////////////////////////////////////////////////////
///////////////////////  OTHER  ////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

    // Function Write Error:
    int three_write(char *str_1, char *str_2, char *str_3);
    int double_write(char *str_1, char *str_2);
    int write_error(char const *str);
    int error_env(char *str_1, char *str_2, char *str_3);
    int write_error_rep(char const *str);

    // Cleaner:
    int dual_rect_error(i_s *info_shell, char *cmd);
    char *cleaner_espace(char *cmd);

    // Init && Free:
    int init_struct(i_s *info_shell, char **env);
    void free_struct(i_s *info_shell);

    //ALIAS
    int my_alias(i_s *info_shell, char *cmd);
    int verif_arg_alias(char **cmd);
    void check_allias(char **one_arg, char **cmd, i_s *info_shell);
    void fill_alias_end(i_s *info_shell, char *temp);
    void fill_alias_debut(i_s *info_shell, char *temp);
    char *cut_str(char *str);
    void check_aliases_suite(char **one_arg, char **cmd,
    i_s *info_shell, int i);
    int count_double_arr(char **arr);
    int my_putstr(char const *str);
    char * my_strcat ( char * dest , char const * src );
    void find_alias(i_s *info_shell, char *cmd, char *one_arg);
    int print_alias_one_arg(i_s *info_shell, char **temp);
    int my_unalias(i_s *info_shell, char *cmd);
    void my_alias_end(i_s *info_shell, char *temp_sec);
    int find_same_allias(i_s *info_shell, char *temp, char *temp2);
    void adjust_tmp(char **tmp_j);
    void replace_tmp(char **tmp_j, char *cmd);
    void sig_error(i_s *info_shell, int status);
    void process_aliases_suite(int *lock, i_s *info_shell, char **tmp, int j);

    //////Varible ENV
    void stock_variable(i_s *info_shell);
    int my_letter_isalpha ( char const str );
    void fill_name_and_cmd(i_s *info_shell, int *i, int *k, char *temp);
    int error_env_fill(i_s *info_shell, int *i, int j);
    int if_arg_variable_env(i_s *info_shell, char *cmd, char **new_cmd);
    void stock_setenv_loc(i_s *info_shell, char **tab_cmd);
    void find_home(i_s *info_shell);
    int check_if_varenv(char *cmd);
    int if_arg_variable_env_suite(i_s *info_shell, char **temp, int k);
    int check_special_var(i_s *info_shell, char *cmd);
    int start_cmd_debut(i_s *info_shell, char **cmd);
    void star_cmd_suite(i_s *info_shell, int tmp);
    void if_arg_variable_env_sec(char **new_cmd, char **temp, int tail);

    //CLEAN
    char *cleaner_backsticks(char *tab_cmd);
    char *cleaner_parentheses(char *tab_cmd);
    int error_is_one(i_s *info_shell, char *cmd);

    //WHERE WICH
    int where(i_s *info_shell, char *cmd);
    int which(i_s *info_shell, char *cmd);
    int is_executable(char *filename);
    int verif_where(char **temp, int i, i_s *info_shell);
    int is_builtin_cmd(char *temp);
    int where_alias(i_s *info_shell, char *temp);
    int where_sec(char *temp);
    int where_end(i_s *info_shell, char **temp, int nb_arr, int nb_return);


////////////////////////////////////////////////////////////////////////////////
///////////////////////  COLOR  ////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

    // Color:
    #define CDEF  "\x1B[0m"

    #define CBLD  "\x1B[1m"
    #define CFNT  "\x1B[2m"
    #define CITA  "\x1B[3m"
    #define CUND  "\x1B[4m"
    #define CINV  "\x1B[7m"
    #define CTGH  "\x1B[9m"
    #define CBLK  "\x1B[30m"
    #define CRED  "\x1B[31m"
    #define CGRN  "\x1B[32m"
    #define CYEL  "\x1B[33m"
    #define CBLU  "\x1B[34m"
    #define CMAG  "\x1B[35m"
    #define CCYN  "\x1B[36m"
    #define CWHT  "\x1B[37m"
