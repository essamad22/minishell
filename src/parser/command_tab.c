/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhtab <aakhtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 21:33:53 by aakhtab           #+#    #+#             */
/*   Updated: 2023/11/12 18:49:33 by aakhtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_cmd_tab	*command_tab(char *cmd_line)
{
	t_item		*tokens;
	t_cmd_tab	*cmd_tab;

	tokens = lexer(cmd_line);
	delete_spaces(&tokens);
	tokens_iterator(tokens, cmd_tab);
	check_end_quots(&tokens);
	g_data.syntax_error = check_quote(&tokens);
	remove_quotes(&tokens);
	fill_cmd(&tokens, &cmd_tab);
    // print_tokens(tokens);
	syntax_error(&tokens);
	clear_tokens(&tokens);
	return (cmd_tab);
}

int	cmd_len(t_item *tokens)
{
	int	size;

	size = 1;
	if (!tokens)
		return (0);
	while (tokens)
	{
		if (tokens && tokens->type == PIPE && tokens->state == GENERAL)
			size++;
		tokens = tokens->next;
	}
	return (size);
}

void print_tokens(t_item *tokens)
{
    t_item  *tmp;

    tmp = tokens;
    printf("\033[0;1;2;31m-------------------------------------------------------------------------------------------------------------------------\n");
    printf("\tCONTENT\t\t|\tLEN\t\t|\tTYPE\t\t|\tSTATE\t\t|\tAMBIGUOS\t|\n");
    printf("-------------------------------------------------------------------------------------------------------------------------\033[0;37m\n");
    while (tmp)
    {
        printf("\t %s\t", tmp->content);
        printf("\t|\t %d \t", tmp->len);
        if (tmp->type == WORD)
            printf("\t|\t WORD \t");
        else if (tmp->type == PIPE)
            printf("\t|\t PIPE \t");
        else if (tmp->type == SPAC)
            printf("\t|\t SPAC \t");
        else if (tmp->type == LESS)
            printf("\t|\t LESS \t");
        else if (tmp->type == GREAT)
            printf("\t|\t GREAT \t");
        else if (tmp->type == QUOTE)
            printf("\t|\t QUOTE \t");
        else if (tmp->type == DQUOTE)
            printf("\t|\t DQUOTE ");
        else if (tmp->type == ENV)
            printf("\t|\t ENV \t");
        else if (tmp->type == HEREDOC)
            printf("\t|\t HEREDOC");
        else if (tmp->type == APPEND)
            printf("\t|\t APPEND");
        if (tmp->state == GENERAL)
            printf("\t|\t GENERAL");
        else if (tmp->state == IN_QUOTE)
            printf("\t|\t IN_QUOTE");
        else if (tmp->state == IN_DQUOTE)
            printf("\t|\t IN_DQUOTE");
        if (tmp->is_ambiguous == 1)
        {
            printf("\t|\t TRUE\t\t|");
        }
        else
            printf("\t|\t FALSE\t\t|");
        printf("\n-------------------------------------------------------------------------------------------------------------------------\n");
        tmp = tmp->next;
    }
}
