/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   item_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhtab <aakhtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:05:55 by aakhtab           #+#    #+#             */
/*   Updated: 2023/11/12 13:30:21 by aakhtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_item	*new_item(char *value, int len, int type, int stat)
{
	t_item	*item;

	item = (t_item *)malloc(sizeof(t_item));
	if (item == NULL)
		return (NULL);
	item->content = value;
	item->len = len;
	item->type = type;
	item->state = stat;
	item->is_ambiguous = 0;
	item->next = NULL;
	item->prev = NULL;
	item->tail = item;
	return (item);
}

void	add_item(t_item **list, t_item *new_item)
{
	if ((*list) == NULL)
	{
		(*list) = new_item;
		(*list)->tail = new_item;
		(*list)->head = new_item;
		(*list)->next = NULL;
	}
	else
	{
		new_item->prev = (*list)->tail;
		(*list)->tail->next = new_item;
		new_item->next = NULL;
		new_item->head = (*list);
		(*list)->tail = new_item;
	}
}

void	rm_item(t_item **items)
{
	t_item	*save_next;

	save_next = (*items)->next;
	if ((*items)->prev == NULL)
	{
		(*items)->head = (*items)->next;
		if ((*items)->next != NULL)
			(*items)->next->prev = NULL;
	}
	else if ((*items)->next == NULL)
	{
		(*items)->tail = (*items)->prev;
		if ((*items)->prev != NULL)
			(*items)->prev->next = NULL;
	}
	else
	{
		(*items)->prev->next = (*items)->next;
		(*items)->next->prev = (*items)->prev;
	}
	free((*items)->content);
	(*items)->content = NULL;
	free((*items));
	(*items) = save_next;
}

void	clear_tokens(t_item **tokens)
{
	t_item	*tmp;

	while ((*tokens))
	{
		tmp = (*tokens)->next;
		free((*tokens)->content);
		(*tokens)->content = NULL;
		free((*tokens));
		(*tokens) = tmp;
	}
}
