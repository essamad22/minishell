/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   re_token.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasrollahkhachabi <nasrollahkhachabi@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 01:20:22 by aakhtab           #+#    #+#             */
/*   Updated: 2023/11/02 18:01:40 by nasrollahkh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void    delete_spaces(t_item **tokens)
{
    t_item  *tmp;
    t_item  *holder;
    
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
    // printf("after delete spaces\n");
}

void    remove_quotes(t_item **tokens)
{
    t_item  *tmp;
    
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