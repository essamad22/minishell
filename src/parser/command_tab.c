/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhtab <aakhtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 21:33:53 by aakhtab           #+#    #+#             */
/*   Updated: 2023/11/12 13:27:29 by aakhtab          ###   ########.fr       */
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
