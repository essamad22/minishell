/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhtab <aakhtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 21:21:54 by aakhtab           #+#    #+#             */
/*   Updated: 2023/11/02 16:39:49 by aakhtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "minishell.h"
# include "lexer.h"

typedef struct s_redir
{
    char            *redirect;
    int             type;
    struct s_redir  *next;
}   t_redir;

typedef struct s_cmd_tab
{
    char                **cmd;
    t_redir             *redirs;
    int                 is_pipe;
    // int                 len;
    struct s_cmd_tab    *next;
}           t_cmd_tab;

typedef struct s_env_list
{
    char                *name;
    char                *value;
    struct s_env_list   *next;
}   t_env_list;

t_cmd_tab   *command_tab(char *cmd_line);
int         cmd_len(t_item *tokens);

char        **ft_envdup(char **env);
t_env_list  *ft_envlst(char **env);
void        add_env(t_env_list **env_lst, t_env_list *new);
t_env_list  *new_env(char *env);

void        tokens_iterator(t_item *tokens, t_cmd_tab *cmd_tab);
int         expand(t_item **tokens);
int         fill_env(t_item **tokens, t_env_list *env);
t_env_list  *get_var(t_item *token, t_env_list *env_lst);
void        delete_spaces(t_item **tokens);
void        remove_quotes(t_item **tokens);
void        check_quote(t_item **tokens);
void        join_in_quots(t_item **tokens);
void        fill_cmd(t_item **tokens, t_cmd_tab **cmd_tab);
void        iterate_redir(t_item *tmp, t_cmd_tab **cmd_tab);
void        print_cmd_tab(t_cmd_tab **cmd_tab);
void        add_cmd_tab(t_cmd_tab **cmd_tab, t_cmd_tab *new_cmd_tab, int pipe);
t_cmd_tab   *new_cmd(t_item *token, int *pipe);
// t_item      *inside_quotes(t_cmd_tab *cmd, t_item **tokens);
// void        is_env(t_item **tokens, t_tokens type);
void        add_redir(t_redir **redirs, t_redir *new_redir);
t_redir     *new_redir(t_item *token, int type);

int         strlen_2d(char **str);
void        ft_free_2d(char **str);
void        free_redir(t_redir **redir);
void        clear_data(t_cmd_tab **cmd_tab);
void        clear_tokens(t_item **tokens);
int         len_of_cmd(t_item *token);
char        **creat_cmd(t_item *token);

#endif