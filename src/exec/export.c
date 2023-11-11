/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhtab <aakhtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 03:47:56 by aakhtab           #+#    #+#             */
/*   Updated: 2023/11/11 20:22:38 by aakhtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	check_cmd(char *cmd)
{
	int	i;

	i = -1;
	while (cmd[++i])
	{
		if (!ft_isalnum(cmd[i]))
			return (0);
	}
	return (1);
}

void	print_export(char *s, int fd)
{
	int		i;
	int		l;

	i = 0;
	while (s[i] && s[i - 1] != '=')
		ft_putchar_fd(s[i++], fd);
	l = i - 1;
	if (s[l] == '=')
	{
		ft_putchar_fd('\"', fd);
		while (s[i])
			ft_putchar_fd(s[i++], fd);
		ft_putchar_fd('\"', fd);
	}
}

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

int	iterate_export(t_vr *vr, char *target)
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

void	check_exp_env(char *cmd, t_vr *vr)
{
	int		l;
	char	*word;

	word = unset_word(cmd);
	l = iterate_export(vr, word);
	if (l > 0 && ft_strnstr(cmd, "=", ft_strlen(cmd)) && check_cmd(word))
	{
		free(vr->env[l]);
		vr->env[l] = ft_strdup(cmd);
	}
	else if (ft_isalpha(cmd[0]) && check_cmd(word)
		&& iterate_export(vr, word) == -1)
	{
		vr->env = add_to_export(vr->env, cmd);
		add_env(&g_data.env_lst, new_env(cmd));
		vr->envlen += 1;
	}
	else if (ft_strnstr(cmd, "+=", ft_strlen(cmd)))
    {
        char *delimeter = ft_strnstr(cmd, "+=", ft_strlen(cmd));
        char *tmp = cmd;
        while(tmp && tmp != delimeter)
        {
            if(*tmp == '+')
            {
                ft_error("not a valid identifier\n", 1);
	            free (word);
	            g_data.exit_status = 1;
                return ;
            }
            tmp++;
        }
        char *trimedWord = ft_strtrim(word, "+");
        // if (trimedWord) check for not a valid identifier "espace"
        l = iterate_export(vr, trimedWord);
        if (l == -1)
        {
            vr->env = add_to_export(vr->env, cmd);
            add_env(&g_data.env_lst, new_env(cmd));
            vr->envlen += 1;
        }
        else
        {
            char *new = ft_strjoin(vr->env[l], ft_strchr(cmd, '=') + 1);
            vr->env[l] = new;
            free (trimedWord);
        }
    }
	else if (!ft_isalpha(cmd[0]) || !check_cmd(word))
    {
		ft_error("not a valid identifier\n", 1);
	    free (word);
	    g_data.exit_status = 1;
        return ;
    }
	free (word);
	g_data.exit_status = 0;
}
