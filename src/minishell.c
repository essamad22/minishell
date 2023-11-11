/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhtab <aakhtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 06:01:06 by aakhtab           #+#    #+#             */
/*   Updated: 2023/11/12 00:00:41 by aakhtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_data	g_data;

char	*ft_readline(void)
{
	char	*line;

	line = readline(C_GREEN "MINISHELL $> " C_RESET);
	return (line);
}

void	set_data(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
    g_data.syntax_error = 0;
	g_data.env_dup = ft_envdup(env);
	g_data.env_lst = ft_envlst(env);
	g_data.exit_status = 0;
}

void	handle_sigint(int sigint)
{
	(void) sigint;
	g_data.exit_status = 1;
	if (g_data.flag)
	{
		g_data.exitheredoc = 1;
		printf("\n");
		close(0);
		g_data.flag = 0;
	}
	else
	{
		if (!g_data.h_sig)
			printf("\n");
		rl_on_new_line();
		rl_redisplay();
	}
}

t_vr	*init_vr(char **env)
{
	g_data.fd = dup(0);
	g_data.exit_status = 0;
	signal(SIGINT, &handle_sigint);
	signal(SIGQUIT, SIG_IGN);
	return (fill_env2(env));
}

//Undefined symbols for architecture
void	clear_data(t_cmd_tab **tmp)
{
	t_cmd_tab	*tmp2;

	while ((*tmp))
	{
		ft_free_2d((*tmp)->cmd);
		if ((*tmp)->redirs)
			free_redir(&(*tmp)->redirs);
		tmp2 = (*tmp);
		(*tmp) = (*tmp)->next;
		free(tmp2);
	}
	free(*tmp);
}
//Undefined symbols for architecture

int	main(int ac, char **av, char **env)
{
	char *line;
	t_cmd_tab *cmd_tab;
	t_vr *vr;

	line = NULL;
	vr = init_vr(env);
	set_data(ac, av, env);
	while (1)
	{
		cmd_tab = NULL;
		line = ft_readline();
		if (line == NULL)
			break ;
		add_history(line);
		// this line for remove spaces from the begining and the end of the line
		line = ft_strtrim(line, " ");
		// ------------------------------
		// this if for check if the line is empty or not to not segfault because of EMPTY LINE
		cmd_tab = command_tab(line);
		if (ft_strlen(line) != 0 && g_data.syntax_error >= 0)
		{
			if (cmd_tab == NULL)
				break ;
			exec_pipe(cmd_tab, vr);
		}
		free(line);
		clear_data(&cmd_tab);
		free(cmd_tab);
	}
    // free(line);
	// clear_data(&cmd_tab);
	// free(cmd_tab);
	return (0);
}