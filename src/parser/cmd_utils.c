/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhtab <aakhtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 10:26:02 by aakhtab           #+#    #+#             */
/*   Updated: 2023/11/12 13:33:37 by aakhtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	creat_cmd(t_item *token, t_cmd_tab **cmd_tab)
{
	char	**cmd;
	int		len;

	*cmd_tab = (t_cmd_tab *)ft_calloc(sizeof(t_cmd_tab), 1);
	len = len_of_cmd(token);
	cmd = (char **)ft_calloc(sizeof(char *), (len + 1));
	if (!cmd)
	{
		(*cmd_tab)->cmd = NULL;
		(*cmd_tab)->is_pipe = 0;
		return ;
	}
	(*cmd_tab)->cmd = cmd;
	(*cmd_tab)->is_pipe = 0;
	return ;
}

t_cmd_tab	*new_cmd(t_item *token, int *pipe)
{
	t_cmd_tab	*cmd_tab;
	int			i;

	creat_cmd(token, &cmd_tab);
	i = 0;
	while (token)
	{
		if (token->type == PIPE && token->state == GENERAL)
		{
			*pipe += 1;
			cmd_tab->is_pipe = 1;
			break ;
		}
		else if (token->type == WORD && (token->state == GENERAL
				|| token->state == IN_QUOTE || token->state == IN_DQUOTE))
		{
			cmd_tab->cmd[i++] = ft_strdup(token->content);
			cmd_tab->cmd[i] = NULL;
		}
		else if (token->type == HEREDOC || token->type == APPEND
			|| token->type == GREAT || token->type == LESS)
			iterate_redir(&token, &cmd_tab);
		token = token->next;
	}
	return (cmd_tab);
}

void	add_cmd_tab(t_cmd_tab **cmd_tab, t_cmd_tab *new_cmd_tab, int pipe)
{
	t_cmd_tab	*tmp;

	if (pipe == 0)
		(*cmd_tab) = new_cmd_tab;
	else
	{
		tmp = *cmd_tab;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_cmd_tab;
	}
}

int	len_of_cmd(t_item *token)
{
	int	len;

	len = 0;
	if (!token)
		return (0);
	while (token)
	{
		if (token->type == WORD && (token->state == GENERAL
				|| token->state == IN_QUOTE || token->state == IN_DQUOTE))
			len++;
		token = token->next;
	}
	return (len);
}
