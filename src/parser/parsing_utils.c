/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhtab <aakhtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 10:22:59 by aakhtab           #+#    #+#             */
/*   Updated: 2023/11/11 23:48:33 by aakhtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	tokens_iterator(t_item *tokens, t_cmd_tab *cmd_tab)
{
	(void)cmd_tab;
	while (tokens)
	{
		if (tokens && tokens->type == ENV && (tokens->state == GENERAL
				|| tokens->state == IN_DQUOTE))
			tokens->is_ambiguous = expand(&tokens);
		if (tokens)
			tokens = tokens->next;
	}
}

t_env_list	*get_var(t_item *token, t_env_list *env_lst)
{
	t_env_list	*tmp;

	tmp = env_lst;
	while (tmp)
	{
		if (ft_strcmp(tmp->name, token->content + 1) == 0)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

void	fill_cmd(t_item **tokens, t_cmd_tab **cmd_tab)
{
	t_item	*tmp;
	int		pipe;

	tmp = *tokens;
	pipe = 0;
	tmp = tmp->next;
	while (tmp)
	{
		if (pipe > 0)
			tmp = tmp->next;
		add_cmd_tab(cmd_tab, new_cmd(tmp, &pipe), pipe);
		while (tmp->next && tmp->next->type != PIPE)
			tmp = tmp->next;
		tmp = tmp->next;
	}
}

void	iterate_redir(t_item *tmp, t_cmd_tab **cmd_tab)
{
	if (tmp->type == GREAT && tmp->next && tmp->next->type == WORD)
		add_redir(&(*cmd_tab)->redirs, new_redir(tmp->next, GREAT));
	else if (tmp->type == LESS && tmp->next && tmp->next->type == WORD)
		add_redir(&(*cmd_tab)->redirs, new_redir(tmp->next, LESS));
	else if (tmp->type == APPEND && tmp->next && tmp->next->type == WORD)
		add_redir(&(*cmd_tab)->redirs, new_redir(tmp->next, APPEND));
	else if (tmp->type == HEREDOC && tmp->next && tmp->next->type == WORD)
		add_redir(&(*cmd_tab)->redirs, new_redir(tmp->next, HEREDOC));
}

char	**creat_cmd(t_item *token)
{
	char	**cmd;
	int		len;

	len = len_of_cmd(token);
	cmd = (char **)calloc(sizeof(char *), (len + 1));
	if (!cmd)
		return (NULL);
	return (cmd);
}

t_cmd_tab	*new_cmd(t_item *token, int *pipe)
{
	t_cmd_tab	*cmd_tab;
	t_item		*tmp;
	int			i;

	tmp = token;
	cmd_tab = (t_cmd_tab *)ft_calloc(sizeof(t_cmd_tab), 1);
	cmd_tab->cmd = creat_cmd(tmp);
	cmd_tab->is_pipe = 0;
	i = 0;
	while (tmp)
	{
		if (tmp->type == PIPE && tmp->state == GENERAL)
		{
			*pipe += 1;
			break ;
		}
		else if (tmp->type == WORD && (tmp->state == GENERAL
					|| tmp->state == IN_QUOTE || tmp->state == IN_DQUOTE))
        {
			cmd_tab->cmd[i++] = ft_strdup(tmp->content);
            cmd_tab->cmd[i] = NULL;
        }
		else if (tmp->type == HEREDOC || tmp->type == APPEND
				|| tmp->type == GREAT || tmp->type == LESS)
		{
			iterate_redir(tmp, &cmd_tab);
			tmp = tmp->next;
		}
		if (*pipe > 0)
			cmd_tab->is_pipe = 1;
		tmp = tmp->next;
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
