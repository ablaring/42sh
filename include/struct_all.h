/*
** EPITECH PROJECT, 2022
** struct_menu.h
** File description:
** struct for all game
*/

#pragma once

///////////////////////// PIPE ///
    typedef struct st_pipe {
        char **tab_pipe;
        int nb_pipe;
        int **pi;
        int pos;
        int pos_max;
        int old;
        int old_out;
        int *waitpid;
    } s_p;

///////////////////////// REDIRECTION ///
    typedef struct st_redi {
        int *redir_type;
        char *redir_file_in;
        char *redir_file_out;
        int err_redir;
        int fd;
        int old;
        char **file_tmp;
        int restart;
        int *pipe_out;
    } s_r;

///////////////////////// CONDITION ///
    typedef struct st_cond {
        int cmd_good; // if == 1 la cmd a fonctionne sinon 0 en cas d'erreur
        int size_cmd_and_or;
        int size_and_or;
    } s_c;

///////////////////////// EDITION ///
    typedef struct st_edit {
        char **history; // Max 50 cmd + max 1024 cara in cmd
        int size_history;
        int *hour;
        int *minute;
        char **list_cmd; // Max 50 cmd + max 1024 cara in cmd
        int size_list_cmd;
        int pos_history; // Position actuelle dans l'historique (a reset h24)
        int size_last_cmd;
        int nb_back; // le nombre de back que le curseur doit faire
        int size_term;
        int reset;
        int pos_in_cmd; // Position dans le char *cmd
        int not_start_cmd;

        char *tmp_tab; // Variable temporaire quand on fait TAB
        char **tmp_display_tab;
        int size_tmp_display_tab;
        int no_file_find; // Aucun fichier ou dossier trouvé
        int is_cmd;
        char *tmp_find_cmd; // Fichier ou dossier trouvé pour auto-complection
    } s_e;

///////////////////////// ALIAS //
    typedef struct ALIAS {
        char *name;
        char *cmd;
        int nb;
    } alias_s;

///////////////////////// ENV //
    typedef struct ENVLOC {
        char *name;
        char *cmd;
        int lock;
    } env_s;

/// @/////////////PARENTHESIS && BACKTICKS//////////
    typedef struct PARBACK {
        char *parenthesis_cmd;
        char *backticks_cmd;
    } par_s;

////////////////////////////////////////////////////////////////////////////////
///////////////////////   PRINCIPAL STRUCT /////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

    typedef struct info_shell {
        char **env;
        int size_env;
        char *tmp_env;
        int tmp_pos_env;
        char *dir;
        char *back_dir;
        int stop; // Pour arrêter le shell
        int restart; // Pour le redem
        int exit_value; //valeur de l'exit
        int return_value; //valeur du return de chaque fonction
        int nb_alias;
        int nb_env;
        int nb_buildin;
        int is_single;
        char *home;
        char **to_sup_unalias;

        s_e st_edit;
        s_c st_cond;
        s_r st_redi;
        s_p st_pipe;
        par_s *is_true;
        alias_s *alias;
        alias_s *new_alias;
        env_s *env_loc;
    } i_s;

    typedef struct st_reset {
        int reset;
    } re_s;

    typedef struct {
        char** files;
        int num_files;
    } FilesResult;
