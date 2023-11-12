/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhachab <nkhachab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 03:48:23 by aakhtab           #+#    #+#             */
/*   Updated: 2023/11/12 10:44:02 by nkhachab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_error(char *msg, int exit_code)
{
	ft_putstr_fd(msg, 2);
	g_data.exit_status = exit_code;
}

int	ft_lstlen(t_cmd_tab *lst)
{
	int			len;
	t_cmd_tab	*tmp;

	tmp = lst;
	len = 0;
	while (tmp)
	{
		len++;
		tmp = tmp->next;
	}
	return (len);
}

void	duplicate_fd(t_cmd_tab *list, t_exec_p *exec)
{
	if (exec->fd[0] != 0)
		dup2(exec->fd[0], 0);
	else if (exec->cmdnbr != 0)
		dup2(exec->p[(exec->cmdnbr - 1) * 2], 0);
	if (exec->fd[1] != 0)
		dup2(exec->fd[1], 1);
	else if (list->next)
		dup2(exec->p[exec->cmdnbr * 2 + 1], 1);
}

char	**add_to_export(char **env, char *elmnt)
{
	char	**s_env;
	int		i;

	i = 0;
	while (env[i++])
		;
	s_env = malloc(sizeof(char *) * (i + 2));
	if (!s_env)
		ft_error("allocation faild\n", 1);
	i = -1;
	while (env[++i])
		s_env[i] = ft_strdup(env[i]);
	s_env[i++] = ft_strdup(elmnt);
	s_env[i] = NULL;
	ft_freetwo(env);
	return (s_env);
}
