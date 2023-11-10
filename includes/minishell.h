/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasrollahkhachabi <nasrollahkhachabi@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 16:01:17 by aakhtab           #+#    #+#             */
/*   Updated: 2023/11/10 06:17:29 by nasrollahkh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../lib/libft.h"
# include "lexer.h"
# include "parser.h"
// # include "execution.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <string.h>
# include <errno.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>

# define C_GREEN   "\033[0;1;3;32m"
# define C_RESET   "\033[0;37m"
# define MAX_LEN 1024



//


typedef struct s_v
{
	int			is_pipe;
	t_cmd_tab		*tmp;
	void		*exec;
	int			i;
	int			j;
	int			status;
	int			len;
	char		*rd;
	int			len_h;
	int			fd[2];

}	t_v;


// t_data	g_data;

typedef struct s_exec_p
{
	int		*fd;
	pid_t	pid;
	int		cmdnbr;
	int		*p;
	int		fd_in;
	int		fd_heredoc;

}	t_exec_p;

typedef struct s_vr
{
	char	**env;
	int		envlen;
	int		flag;

}	t_vr;

void	change_pwdenv(char *oldpwd, t_vr *vr);
void	cd(t_cmd_tab *list, t_vr *vr);
void	pwd(int fd);
int	in_builtin(t_cmd_tab *list);
t_vr	*fill_env2(char **envp);
void	env2(char **cmd, t_vr *vr, int fd);
t_vr	*exec_builtin(t_cmd_tab *list, t_vr *vr, int fd);
int	ft_exit_2(t_cmd_tab *list);
void	ft_exit(t_cmd_tab *list);
void	print_n_echo(char **cmd, int fd, int i);
int	*out_file(t_redir *file,	int *fd);
int	*openfile_ut(t_redir *file,	int *fd);
int	*openfile(t_cmd_tab *list);
void	ft_execve(t_cmd_tab *list, t_vr *vr, char *cmderr);
char	*ft_getpath(char **envp);
char	**get_path_splited(char **envp);
char	*ft_checkaccess(char *cmd, char **env);
void	handle_sig(void);
void	ft_child(t_cmd_tab *list, t_vr *vr, t_exec_p *exec);
void	*exec_pipe_ut(t_cmd_tab *list, t_exec_p *exec, t_vr *vr, int pipe_num);
void	*exec_pipe(t_cmd_tab *list, t_vr *vr);
int	check_cmd(char *cmd);
void	print_export(char *s, int fd);
void	export(t_cmd_tab *list, t_vr *vr, int fd);
int	iterate_export(t_vr *vr, char *target);
void	check_exp_env(char *cmd, t_vr *vr);
int	heredoc_utls(t_v v);
int	heredoc(char *file_name);
int	check_arg(char *arg);
void	print_echo(char **cmd, int fd);
void	echo(t_cmd_tab *list, int fd);
void	ft_freetwo(char **target);
char	**unset_ut(char *arg, char **target, int len);
t_vr	*unset(char **cmd, t_vr *vr);
char	*unset_word(char *target);
void	closepipe_andwait(t_exec_p *exec, t_v *v);
void	ft_error(char *msg, int exit_code);
int	ft_lstlen(t_cmd_tab *lst);
void	duplicate_fd(t_cmd_tab *list, t_exec_p *exec);
char	**add_to_export(char **env, char *elmnt);
t_vr	*exec_builtin(t_cmd_tab *list, t_vr *vr, int fd);
char	*ft_strjoin1(char *s1, char *s2);
void    clear_data(t_cmd_tab **tmp);
t_cmd_tab   *command_tab(char *cmd_line);

//






typedef struct s_data
{
    char        **env_dup;
    t_env_list  *env_lst;
    int         exit_status;
    int         heredoc;
    char			*content; // added by Nasro
	int	exitheredoc;
	int	quit_flag;
	int	here_doc_flag;
	int	rd_error;
	int	cd;
	int fd;
	int flag;
	int	h_sig;
	struct t_data	*next;    // added by Nasro 
}   t_data;


extern t_data g_data;



#endif