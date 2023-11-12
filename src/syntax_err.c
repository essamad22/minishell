/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_err.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhtab <aakhtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 21:45:17 by aakhtab           #+#    #+#             */
/*   Updated: 2023/11/12 12:01:22 by aakhtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void    syntax_error(t_item **tokens)
{
    check_pipes(&(*tokens));
    if (g_data.syntax_error == -1)
        ft_error("minishell: syntax error near unexpected token `\"'\n", 2);
    else if (g_data.syntax_error == -2)
        ft_error("minishell: syntax error near unexpected token `\''\n", 2);
    else if (g_data.syntax_error == -3)
        ft_error("minishell: syntax error near unexpected token `|'\n", 2);
    else if (g_data.syntax_error == -4)
        ft_error("minishell: syntax error near unexpected token `newline'\n", 2);
}

void    check_pipes(t_item **tokens)
{
    t_item  *tmp;

    tmp = *tokens;
    tmp = tmp->next;
    if (tmp->type == PIPE && tmp->state == GENERAL)
    {
        g_data.syntax_error = -3;
        return ;
    }
    while (tmp)
    {
        if (tmp->type == PIPE && tmp->state == GENERAL && !tmp->next->content)
        {
            g_data.syntax_error = -3;
            return ;
        }
        else if (tmp->type == PIPE && tmp->state == GENERAL 
            && tmp->next->type == PIPE && tmp->next->state == GENERAL)
        {
            g_data.syntax_error = -3;
            return ;
        }
        tmp = tmp->next;
    }
}

void    check_end_quots(t_item **tokens)
{
    t_item  *tmp;

    tmp = *tokens;
    g_data.empty_quote = 0;
    while (tmp)
    {
        if (tmp->type == QUOTE && tmp->state == GENERAL 
            && tmp->next->type == QUOTE && tmp->next->state == GENERAL)
        {
            g_data.empty_quote = 1;
            return ;
        }
        else if (tmp->type == DQUOTE && tmp->state == GENERAL 
            && tmp->next->type == DQUOTE && tmp->next->state == GENERAL)
        {
            g_data.empty_quote = 1;
            return ;
        }
        tmp = tmp->next;
    }
}
