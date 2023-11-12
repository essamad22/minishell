/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhtab <aakhtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 03:48:39 by aakhtab           #+#    #+#             */
/*   Updated: 2023/11/12 13:58:39 by aakhtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include "minishell.h"
# include "parser.h"

typedef struct s_v
{
	int			is_pipe;
	t_cmd_tab	*tmp;
	void		*exec;
	int			i;
	int			j;
	int			status;
	int			len;
	char		*rd;
	int			len_h;
	int			fd[2];

}				t_v;

typedef struct s_vr
{
	char		**env;
	int			envlen;
	int			flag;
	struct s_vr	*next;

}				t_vr;

typedef struct s_exec_p
{
	int			*fd;
	pid_t		pid;
	int			cmdnbr;
	int			*p;
	int			fd_in;
	int			fd_heredoc;

}				t_exec_p;

void			change_pwdenv(char *oldpwd, t_vr *vr);
void			ft_exit(t_cmd_tab *cmd);
void			cd(t_cmd_tab *list, t_vr *vr);
void			pwd(int fd);
int				in_builtin(t_cmd_tab *list);
t_vr			*fill_env2(char **envp);
void			env2(char **cmd, t_vr *vr, int fd);
t_vr			*exec_builtin(t_cmd_tab *list, t_vr *vr, int fd);
int				ft_exit_2(t_cmd_tab *list);
void			ft_exit(t_cmd_tab *list);
void			print_n_echo(char **cmd, int fd, int i);
int				*out_file(t_redir *file, int *fd);
int				*openfile_ext(t_redir *file, int *fd);
int				*openfile(t_cmd_tab *list);
void			ft_execve(t_cmd_tab *list, t_vr *vr, char *cmderr);
char			*ft_getpath(char **envp);
char			**get_path_splited(char **envp);
char			*ft_checkaccess(char *cmd, char **env);
void			handle_sig(void);
void			ft_child(t_cmd_tab *list, t_vr *vr, t_exec_p *exec);
void			*exec_pipe_ext(t_cmd_tab *list, t_exec_p *exec, t_vr *vr,
					int pipe_num);
void			*exec_pipe(t_cmd_tab *list, t_vr *vr);
int				check_cmd(char *cmd);
void			print_export(char *s, int fd);
void			export(t_cmd_tab *list, t_vr *vr, int fd);
int				export_iterate(t_vr *vr, char *target);
void			check_exp_env(char *cmd, t_vr *vr);
char			*ft_strjoin01(char *s1, char *s2);
int				heredoc_utls(t_v v);
// ------ edit in herdoc function -------
// ------ add int in_quote to t_redir -------
int				heredoc(char *file_name, int in_quote);
// ----------------------------------------
int				check_arg(char *arg);
void			print_echo(char **cmd, int fd);
void			echo(t_cmd_tab *list, int fd);
void			ft_freetwo(char **target);
char			**unset_ut(char *arg, char **target, int len);
t_vr			*unset(char **cmd, t_vr *vr);
char			*unset_word(char *target);
void			closepipe_andwait(t_exec_p *exec, t_v *v);
void			ft_error(char *msg, int exit_code);
int				ft_lstlen(t_cmd_tab *lst);
void			duplicate_fd(t_cmd_tab *list, t_exec_p *exec);
char			**add_to_export(char **env, char *elmnt);
t_vr			*exec_builtin(t_cmd_tab *list, t_vr *vr, int fd);
char			*ft_strjoin1(char *s1, char *s2);
// void			clear_data(t_cmd_tab **tmp);
// t_cmd_tab		*command_tab(char *cmd_line);

//

// =============================================//
// =============== Heredoc utils ===============//

char			*lexer_heredoc(char *hd_line);
int				get_token_hd(t_item **list, char *cmd_line, int *stat);
int				word_hd(t_item **list, char *cmd_line, int *stat);
void			join_after_expand(t_item **tokens);
int				file_inquotes(char *file);
void					free_vr(t_vr *vr);

#endif