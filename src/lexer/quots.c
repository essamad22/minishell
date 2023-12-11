/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quots.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhtab <aakhtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 20:41:40 by aakhtab           #+#    #+#             */
/*   Updated: 2023/11/12 13:29:48 by aakhtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	in_quote(t_item **list, char type, int *stat)
{
	if (type == QUOTE)
		return (s_quote(list, stat, QUOTE));
	else
		return (d_quote(list, stat, DQUOTE));
}

int	s_quote(t_item **list, int *stat, int type)
{
	if (*stat == GENERAL)
	{
		add_item(list, new_item(ft_strdup("\'"), 1, type, *stat));
		*stat = IN_QUOTE;
		return (1);
	}
	else if (*stat == IN_DQUOTE)
		*stat = IN_DQUOTE;
	else
		*stat = GENERAL;
	add_item(list, new_item(ft_strdup("\'"), 1, type, *stat));
	return (1);
}

int	d_quote(t_item **list, int *stat, int type)
{
	if (*stat == GENERAL)
	{
		add_item(list, new_item(ft_strdup("\""), 1, type, *stat));
		*stat = IN_DQUOTE;
		return (1);
	}
	else if (*stat == IN_QUOTE)
		*stat = IN_QUOTE;
	else
		*stat = GENERAL;
	add_item(list, new_item(ft_strdup("\""), 1, type, *stat));
	return (1);
}

int	check_quote(t_item **tokens)
{
	t_item	*tmp;
	int		i;
	int		j;

	tmp = *tokens;
	i = 0;
	j = 0;
	while (tmp)
	{
		if (tmp->type == DQUOTE && tmp->state == GENERAL)
			i++;
		else if (tmp->type == QUOTE && tmp->state == GENERAL)
			j++;
		tmp = tmp->next;
	}
	if (i % 2 != 0)
		return (-1);
	if (j % 2 != 0)
		return (-2);
	else
	{
		join_in_quots(&(*tokens));
		return (0);
	}
}
