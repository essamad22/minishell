/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhachab <nkhachab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 03:47:51 by aakhtab           #+#    #+#             */
/*   Updated: 2023/11/12 12:04:40 by nkhachab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	handle_sig(void)
{
	signal(SIGQUIT, SIG_DFL);
	signal(SIGINT, SIG_DFL);
}

char	*prepare_command(t_cmd_tab *list, t_vr *vr, t_exec_p *exec)
{
	char	*cmd;
	char	**tmp;

	handle_sig();
	if (!list->cmd[0])
		return (NULL);
	duplicate_fd(list, exec);
	if (in_builtin(list))
	{
		exec_builtin(list, vr, 1);
		exit(0);
	}
	if (access(list->cmd[0], X_OK) && !in_builtin(list))
	{
		tmp = get_path_splited(vr->env);
		cmd = ft_checkaccess(list->cmd[0], tmp);
		ft_free_2d(tmp);
		if (cmd != NULL)
		{
			free(list->cmd[0]);
			list->cmd[0] = cmd;
		}
	}
	return (list->cmd[0]);
}

void	ft_child(t_cmd_tab *list, t_vr *vr, t_exec_p *exec)
{
	int		i;
	char	*cmderr;

	i = 0;
	cmderr = prepare_command(list, vr, exec);
	while (i < list->is_pipe * 2)
		close(exec->p[i++]);
	ft_execve(list, vr, cmderr);
	free(cmderr);
}

void	*exec_pipe_ext(t_cmd_tab *list, t_exec_p *exec, t_vr *vr, int pipe_num)
{
	exec->fd = openfile(list);
	if (!exec->fd)
		return (NULL);
	list->is_pipe = pipe_num;
	if (!list->next && in_builtin(list) && exec->cmdnbr == 0)
	{
		if (exec->fd[1] != 0)
			vr = exec_builtin(list, vr, exec->fd[1]);
		else
			vr = exec_builtin(list, vr, 1);
	}
	else if (list->cmd[0] && !g_data.exitheredoc && !g_data.rd_error)
	{
		signal(SIGINT, SIG_IGN);
		exec->pid = fork();
		if (exec->pid == 0)
			ft_child(list, vr, exec);
	}
	return ("OK");
}

void	*exec_pipe(t_cmd_tab *list, t_vr *vr)
{
	t_exec_p	*exec;
	t_v			v;

	if (!list)
		return (NULL);
	v.tmp = list;
	exec = malloc(sizeof(t_exec_p));
	exec->cmdnbr = 0;
	v.is_pipe = ft_lstlen(list);
	exec->p = malloc(sizeof(int) * v.is_pipe * 2);
	v.i = -1;
	while (++v.i < v.is_pipe)
		pipe(exec->p + v.i * 2);
	exec->fd_in = 0;
	while (list)
	{
		exec_pipe_ext(list, exec, vr, v.is_pipe);
		list = list->next;
		exec->cmdnbr++;
		free(exec->fd);
	}
	closepipe_andwait(exec, &v);
	return (NULL);
}
