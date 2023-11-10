/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhtab <aakhtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:23:02 by aakhtab           #+#    #+#             */
/*   Updated: 2023/11/10 06:08:59 by aakhtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_redir	*new_redir(t_item *token, int type)
{
	t_redir	*redir;

	redir = (t_redir *)malloc(sizeof(t_redir));
	redir->redirect = ft_strdup(token->content);
	redir->type = type;
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
