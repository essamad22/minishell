/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quots_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhtab <aakhtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:26:40 by aakhtab           #+#    #+#             */
/*   Updated: 2023/11/12 13:25:56 by aakhtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	join_in_quots(t_item **tokens)
{
	t_item	*tmp;
	t_item	*holder;

	tmp = *tokens;
	while (tmp)
	{
		if (tmp->next && (tmp->type == DQUOTE || tmp->type == QUOTE)
			&& tmp->state == GENERAL && (tmp->next->state == IN_DQUOTE
				|| tmp->next->state == IN_QUOTE))
		{
			tmp = tmp->next;
			while (tmp->next)
			{
				if ((tmp->next->type == DQUOTE || tmp->next->type == QUOTE)
					&& tmp->next->state == GENERAL)
					break ;
				tmp->content = ft_strjoin(tmp->content, tmp->next->content);
				tmp->len = ft_strlen(tmp->content);
				holder = tmp->next;
				rm_item(&holder);
			}
			tmp->type = WORD;
		}
		tmp = tmp->next;
	}
}
