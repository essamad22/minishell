/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhtab <aakhtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 03:48:39 by aakhtab           #+#    #+#             */
/*   Updated: 2023/11/12 12:03:03 by aakhtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

// #include "/Users/nasrollahkhachabi/Desktop/minishell2/src/execution/libft/libft.h"
#include "minishell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h>
#include <signal.h>
#include <errno.h>
# include <readline/readline.h>
# include <readline/history.h>


# define EIAD ": is a directory\n"
# define ENSFD ": No such file or directory\n"
# define ECNF ": command not found\n"
# define EPD ": Permission denied\n"
# define ESYNTX "minishell: syntax error near unexpected token `"
# define EAMBGRD ": ambiguous redirect\n"


// typedef struct t_data
// {
// 	char			*content;
// 	struct t_data	*next;

// }					t_data;

//New Structs

// typedef struct s_redir
// {
//     char            *redirect;
//     int             type;
//     struct s_redir  *next;
// }   t_redir;

// typedef struct s_cmd_tab
// {
//     char                **cmd;
//     t_redir             *redirs;
//     int                 is_pipe;
//     // int                 len;
//     struct s_cmd_tab    *next;
// }           t_cmd_tab;

typedef struct shell
{
	t_redir			*redirct;
	t_cmd_tab		*cmd;
	int				index;
	char			**all_cmds;
	char			**str;
	int				pipe;
	struct shell	*next;
	int				in_id;
	int				out_id;
	int				pid;
	int				dell;
	char			**s1;
}					t_minishell;
//New Structs

typedef struct t_info
{

	int				i_exp;
	int				check;
	int				check1;
	
}					t_info;

typedef struct s_env
{
	char			*var;
	char			*value;
	struct s_env	*prev;
	struct s_env	*next;
}			t_env;

typedef struct s_global
{
	t_env		*env;
	t_env		*export;
}			t_global;

int     strlenhtal(char *s);
void    ft_putstr_fd(char *s, int fd);
void    ft_putchar_fd(char c, int fd);
int     ft_strcmp(const char *s1, const char *s2);
int     ft_strlen1(const char *s);
char	*ft_strjoin10(char *s1, char *s2);
char	*getz(void);
char	*getpwd(void);
void	printerr(char *s1, char *s2, char *s3);
char	*ft_strjoin1(char *s1, char *s2);
int     checktossawiplace(char *s);
char	*bringbeforetossawi(char *s);
char	*bringaftertossawi(char *s);
void	ft_exit(t_cmd_tab *cmd);
// int	ft_cd(t_list *p, t_data **data);
// void	ft_export(t_list *p, t_data **data, t_info *info);
// int	ft_unset(t_list *p, t_data **data);
void    one_cmd(int argc, char *argv[], char **envp);
// int     ft_strncmp(const char *s1, const char *s2, size_t n);

// ==========================================
// Heredoc utils ===============

char    *lexer_heredoc(char *hd_line);
int get_token_hd(t_item **list, char *cmd_line, int *stat);
int word_hd(t_item **list, char *cmd_line, int *stat);
void	join_after_expand(t_item **tokens);
// int     file_inquotes(char *file);

#endif