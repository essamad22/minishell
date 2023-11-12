/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhtab <aakhtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 03:47:56 by aakhtab           #+#    #+#             */
/*   Updated: 2023/11/12 13:08:30 by aakhtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	export(t_cmd_tab *list, t_vr *vr, int fd)
{
	int	i;
	int	j;

	i = 0;
	while (list->cmd[++i])
		check_exp_env(list->cmd[i], vr);
	if (i == 1)
	{
		j = 0;
		while (vr->env[++j])
		{
			ft_putstr_fd("declare -x ", fd);
			print_export(vr->env[j], fd);
			ft_putstr_fd("\n", fd);
		}
		g_data.exit_status = 0;
	}
}

int	export_iterate(t_vr *vr, char *target)
{
	int	i;

	i = -1;
	while (vr->env[++i])
	{
		if (!ft_strncmp(vr->env[i], target, ft_strlen(target)))
			return (i);
	}
	return (-1);
}

int	check_valid_var_name(char *cmd)
{
	char	*delimiter;
	char	*tmp;

	delimiter = ft_strnstr(cmd, "+=", ft_strlen(cmd));
	tmp = cmd;
	while (tmp && tmp != delimiter)
	{
		if (*tmp == '+')
		{
			ft_error("not a valid identifier\n", 1);
			return (0);
		}
		tmp++;
	}
	return (1);
}

void	handle_append_env(t_vr *vr, char *cmd, int l)
{
	char	*trimmed_word;
	char	*new;
	char	*tmp;

	tmp = unset_word(cmd);
	if (!check_valid_var_name(cmd))
		return ;
	trimmed_word = ft_strtrim(tmp, "+");
	l = export_iterate(vr, trimmed_word);
	if (!ft_isalpha(cmd[0]) || !check_cmd(trimmed_word))
		ft_error("not a valid identifier\n", 1);
	else if (l == -1)
	{
		vr->env = add_to_export(vr->env, cmd);
		add_env(&g_data.env_lst, new_env(cmd));
		vr->envlen += 1;
	}
	else
	{
		new = ft_strjoin(vr->env[l], ft_strchr(cmd, '=') + 1);
		free(vr->env[l]);
		vr->env[l] = new;
	}
	free(trimmed_word);
	free(tmp);
}

void	check_exp_env(char *cmd, t_vr *vr)
{
	int		l;
	char	*word;

	word = unset_word(cmd);
	l = export_iterate(vr, word);
	if (l > 0 && ft_strnstr(cmd, "=", ft_strlen(cmd)) && check_cmd(word))
	{
		free(vr->env[l]);
		vr->env[l] = ft_strdup(cmd);
	}
	else if (ft_isalpha(cmd[0]) && check_cmd(word) && export_iterate(vr,
			word) == -1)
	{
		vr->env = add_to_export(vr->env, cmd);
		add_env(&g_data.env_lst, new_env(cmd));
		vr->envlen += 1;
	}
	else if (ft_strnstr(cmd, "+=", ft_strlen(cmd)))
		handle_append_env(vr, cmd, l);
	else if (!ft_isalpha(cmd[0]) || !check_cmd(word))
		ft_error("not a valid identifier\n", 1);
	free(word);
	g_data.exit_status = 0;
}
