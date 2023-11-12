/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhtab <aakhtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 03:47:22 by aakhtab           #+#    #+#             */
/*   Updated: 2023/11/12 17:35:44 by aakhtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_vr	*fill_env2(char **envp)
{
	t_vr	*vr;
	int		i;

	i = 0;
    if (!envp || !(*envp))
    {
        vr = malloc(sizeof(t_vr));
        vr->env = NULL;
        return (vr);
    }
    vr = malloc(sizeof(t_vr));
    while (envp[i++])
        ;
    vr->env = malloc(sizeof(char *) * i);
    if (!vr->env)
        ft_error("allocation faild\n", 1);
    i = 0;
    while (envp[i] != NULL)
    {
        vr->env[i] = ft_strdup(envp[i]);
        i++;
    }
    vr->env[i] = NULL;
    vr->envlen = i;
    return (vr);
}

void	env2(char **cmd, t_vr *vr, int fd)
{
	int	i;

	i = 1;
    if (!vr->env)
    {
        ft_error("env : no such file or directory\n", 127);
        return ;
    }
	while (cmd[i])
	{
		ft_error("env : no such file or directory\n", 127);
		return ;
		i++;
	}
	if (i == 1)
	{
		i = -1;
		while (vr->env[++i])
		{
			if (ft_strchr(vr->env[i], '='))
			{
				ft_putstr_fd(vr->env[i], fd);
				ft_putstr_fd("\n", fd);
			}
		}
	}
	g_data.exit_status = 0;
}

t_vr	*exec_builtin(t_cmd_tab *list, t_vr *vr, int fd)
{
	if (list->cmd[0])
	{
		if (!ft_strncmp(list->cmd[0], "echo", ft_strlen("echo"))
			|| !ft_strncmp(list->cmd[0], "/bin/echo", ft_strlen("/bin/echo")))
			echo(list, fd);
		if (!ft_strncmp(list->cmd[0], "cd", 2)
			|| !ft_strncmp(list->cmd[0], "/usr/bin/cd", \
			ft_strlen("/usr/bin/cd")))
			cd(list, vr);
		else if (!ft_strncmp(list->cmd[0], "pwd", 3)
			|| !ft_strncmp(list->cmd[0], "/bin/pwd", ft_strlen("/bin/pwd")))
			pwd(fd);
		else if (!ft_strncmp(list->cmd[0], "export", 6))
			export(list, vr, fd);
		else if (!ft_strncmp(list->cmd[0], "unset", 5))
			vr = unset(list->cmd, vr);
		else if (!ft_strncmp(list->cmd[0], "env", 3)
			|| !ft_strncmp(list->cmd[0], "/usr/bin/env", \
			ft_strlen("/usr/bin/env")))
			env2(list->cmd, vr, fd);
		else if (!ft_strncmp(list->cmd[0], "exit", 4))
			ft_exit(list);
	}
	return (vr);
}

int	ft_exit_2(t_cmd_tab *list)
{
	int	i;
	int	ext;

	i = 0;
	while (list->cmd[++i])
	{
		if (!ft_atoi(list->cmd[i]))
		{
			printf("exit\nexit : numeric argument required\n");
			g_data.exit_status = 255;
			exit (g_data.exit_status);
		}
		else if (ft_atoi(list->cmd[i]) && !list->cmd[i + 1])
		{
			ext = ft_atoi(list->cmd[i]);
			ft_error("exit\n", ft_atoi(list->cmd[i]));
			exit (ext);
		}
		else if (ft_atoi(list->cmd[i]) && ft_atoi(list->cmd[i + 1]))
		{
			ft_error("exit : too many arguments\n", 1);
			return (-1);
		}
	}
	return (i);
}

void	ft_exit(t_cmd_tab *list)
{
	int	i;

	i = ft_exit_2(list);
	if (i == 1)
	{
		printf("exit\n");
		exit(g_data.exit_status);
	}
}
