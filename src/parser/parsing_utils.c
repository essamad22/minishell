/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhtab <aakhtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 10:22:59 by aakhtab           #+#    #+#             */
/*   Updated: 2023/11/12 13:26:14 by aakhtab          ###   ########.fr       */
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

void	iterate_redir(t_item **tmp, t_cmd_tab **cmd_tab)
{
	if ((*tmp)->type == GREAT)
		add_redir(&(*cmd_tab)->redirs, new_redir((*tmp)->next, GREAT));
	else if ((*tmp)->type == LESS)
		add_redir(&(*cmd_tab)->redirs, new_redir((*tmp)->next, LESS));
	else if ((*tmp)->type == APPEND)
		add_redir(&(*cmd_tab)->redirs, new_redir((*tmp)->next, APPEND));
	else if ((*tmp)->type == HEREDOC)
		add_redir(&(*cmd_tab)->redirs, new_redir((*tmp)->next, HEREDOC));
	(*tmp) = (*tmp)->next;
}
