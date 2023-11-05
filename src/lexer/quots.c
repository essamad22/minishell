/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quots.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhtab <aakhtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 20:41:40 by aakhtab           #+#    #+#             */
/*   Updated: 2023/11/04 00:38:43 by aakhtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int in_quote(t_item **list, char type, int *stat)
{
    if (type == QUOTE)
        return (s_quote(list, stat, QUOTE));
    else 
        return (d_quote(list, stat, DQUOTE));
}

int s_quote(t_item **list, int *stat, int type)
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

int d_quote(t_item **list, int *stat, int type)
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

void    check_quote(t_item **tokens)
{
    t_item  *tmp;
    int     i;
    
    tmp = *tokens;
    i = 0;
    while (tmp)
    {
        if (tmp->type == DQUOTE && tmp->state == GENERAL)
            i++;  
        tmp = tmp->next;
    }
    if (i % 2 != 0)
    {
        exit(printf("minishell: syntax error near unexpected token `\"'\n"));
    }
    if ((*tokens)->tail->state == IN_DQUOTE)
    {
        exit(printf("minishell: syntax error near unexpected token `\"'\n"));
    }
    else if ((*tokens)->tail->state == IN_QUOTE)
    {
        exit(printf("minishell: syntax error near unexpected token `'\''\n"));
    }
    else
        return (join_in_quots(&(*tokens)));
}