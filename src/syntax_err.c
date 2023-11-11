/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_err.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhtab <aakhtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 21:45:17 by aakhtab           #+#    #+#             */
/*   Updated: 2023/11/11 23:59:04 by aakhtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void    syntax_error(t_item **tokens)
{
    check_pipes(&(*tokens));
    // check_redirs(tokens);
    if (g_data.syntax_error == -1)
        ft_error("minishell: syntax error near unexpected token `\"'\n", 2);
    else if (g_data.syntax_error == -2)
        ft_error("minishell: syntax error near unexpected token `\''\n", 2);
    else if (g_data.syntax_error == -3)
        ft_error("minishell: syntax error near unexpected token `|'\n", 2);
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
    // while 
    // printf("tokens->type = %s\n", tmp->tail->content);
}