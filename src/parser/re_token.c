/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   re_token.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhtab <aakhtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 01:20:22 by aakhtab           #+#    #+#             */
/*   Updated: 2023/11/12 13:25:39 by aakhtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	delete_spaces(t_item **tokens)
{
	t_item	*tmp;
	t_item	*holder;

	tmp = *tokens;
	while (tmp)
	{
		if (tmp->type == SPAC && tmp->state == GENERAL)
		{
			holder = tmp;
			tmp->prev->next = tmp->next;
			tmp->next->prev = tmp->prev;
			tmp = tmp->next;
			free(holder->content);
			free(holder);
		}
		else
			tmp = tmp->next;
	}
}

void	remove_quotes(t_item **tokens)
{
	t_item	*tmp;

	tmp = *tokens;
	while (tmp)
	{
		if (tmp->type == DQUOTE && tmp->state == GENERAL)
			rm_item(&tmp);
		else if (tmp->type == QUOTE && tmp->state == GENERAL)
			rm_item(&tmp);
		else
			tmp = tmp->next;
	}
}
