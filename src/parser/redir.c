/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhtab <aakhtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:23:02 by aakhtab           #+#    #+#             */
/*   Updated: 2023/11/12 13:25:16 by aakhtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_redir	*new_redir(t_item *token, int type)
{
	t_redir	*redir;

	redir = (t_redir *)malloc(sizeof(t_redir));
	if (!token->content && type == HEREDOC && g_data.empty_quote == 1)
		redir->redirect = ft_strdup("");
	else if (!token->content)
	{
		g_data.syntax_error = -4;
		free(redir);
		return (NULL);
	}
	else
		redir->redirect = ft_strdup(token->content);
	redir->type = type;
	if (token->state == IN_DQUOTE || token->state == IN_QUOTE)
		redir->in_quote = 1;
	else
		redir->in_quote = 0;
	redir->next = NULL;
	return (redir);
}

void	add_redir(t_redir **redirs, t_redir *new_redir)
{
	t_redir	*tmp;

	tmp = *redirs;
	if (tmp == NULL)
		*redirs = new_redir;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_redir;
	}
}
