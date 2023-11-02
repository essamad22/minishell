/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhtab <aakhtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 16:15:00 by aakhtab           #+#    #+#             */
/*   Updated: 2023/10/10 20:39:36 by aakhtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../includes/lexer.h"

t_item		*lexer(char *line)
{
    t_item		*head;
    int         stat;
    int         i;
    
    head = new_item(NULL, 0, WORD, GENERAL);
    stat = GENERAL;
    i = 0;
    while (line[i])
        i += get_token(&head, line + i, &stat);
    return (head);
}
