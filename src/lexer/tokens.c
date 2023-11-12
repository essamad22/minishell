/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhtab <aakhtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 21:36:05 by aakhtab           #+#    #+#             */
/*   Updated: 2023/11/12 16:52:26 by aakhtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	get_token(t_item **list, char *cmd_line, int *stat)
{
	if (*cmd_line == SPAC)
		return (tokens(list, SPAC, stat));
	else if (*cmd_line == PIPE)
		return (tokens(list, PIPE, stat));
	else if (*cmd_line == LESS && cmd_line[1] == LESS)
		return (tokens(list, HEREDOC, stat));
	else if (*cmd_line == LESS)
		return (tokens(list, LESS, stat));
	else if (*cmd_line == GREAT && cmd_line[1] == GREAT)
		return (tokens(list, APPEND, stat));
	else if (*cmd_line == GREAT)
		return (tokens(list, GREAT, stat));
	else if (*cmd_line == ENV)
		return (env(list, cmd_line, stat));
    else if (*cmd_line == TILDE)
        return (env(list, cmd_line, stat));
	else if (*cmd_line == QUOTE)
		return (in_quote(list, QUOTE, stat));
	else if (*cmd_line == DQUOTE)
		return (in_quote(list, DQUOTE, stat));
	else
		return (word(list, cmd_line, stat));
}

int	word(t_item **list, char *cmd_line, int *stat)
{
	int	i;

	i = -1;
	while (cmd_line[++i])
		if (cmd_line[i] == SPAC || cmd_line[i] == PIPE || cmd_line[i] == ENV
			|| cmd_line[i] == LESS || cmd_line[i] == TILDE || cmd_line[i] == GREAT
			|| cmd_line[i] == QUOTE || cmd_line[i] == DQUOTE)
			break ;
	add_item(list, new_item(ft_substr(cmd_line, 0, i), i, WORD, *stat));
	return (i);
}

int	tokens(t_item **list, char type, int *stat)
{
	if (type == PIPE)
		add_item(list, new_item(ft_strdup("|"), 1, PIPE, *stat));
	else if (type == SPAC)
		add_item(list, new_item(ft_strdup(" "), 1, SPAC, *stat));
	else if (type == LESS)
		add_item(list, new_item(ft_strdup("<"), 1, LESS, *stat));
	else if (type == GREAT)
		add_item(list, new_item(ft_strdup(">"), 1, GREAT, *stat));
	else if (type == HEREDOC || type == APPEND)
	{
		if (type == HEREDOC)
			add_item(list, new_item(ft_strdup("<<"), 2, HEREDOC, *stat));
		else
			add_item(list, new_item(ft_strdup(">>"), 2, APPEND, *stat));
		return (2);
	}
	return (1);
}

int	env(t_item **list, char *cmd, int *stat)
{
	int	i;

	i = 0;
	if (cmd[1] == '?')
	{
		add_item(list, new_item(ft_strdup("$?"), 2, ENV, *stat));
		return (2);
	}
    else if (cmd[0] == TILDE)
    {
        add_item(list, new_item(ft_strdup("$HOME"), 1, ENV, *stat));
        return (1);
    }
	while (cmd[++i])
		if (!ft_isenv(cmd[i]))
			break ;
	add_item(list, new_item(ft_substr(cmd, 0, i), i, ENV, *stat));
	return (i);
}
