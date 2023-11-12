/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_err.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhtab <aakhtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 21:45:17 by aakhtab           #+#    #+#             */
/*   Updated: 2023/11/12 18:51:00 by aakhtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	check_redir_err(t_item **tokens)
{
	t_item	*tmp;

	tmp = *tokens;
	while (tmp)
	{
		if (tmp->type == GREAT && tmp->state == GENERAL
			&& tmp->next->type != WORD && tmp->next->state == GENERAL)
			return ((void)(g_data.syntax_error = -5));
		else if (tmp->type == LESS && tmp->state == GENERAL
			&& tmp->next->type != WORD && tmp->next->state == GENERAL)
			return ((void)(g_data.syntax_error = -5));
		else if (tmp->type == APPEND && tmp->state == GENERAL
			&& tmp->next->type != WORD && tmp->next->state == GENERAL)
			return ((void)(g_data.syntax_error = -5));
		else if (tmp->type == HEREDOC && tmp->state == GENERAL
			&& tmp->next->type != WORD && tmp->next->state == GENERAL)
			return ((void)(g_data.syntax_error = -5));
		tmp = tmp->next;
	}
}

void	syntax_error(t_item **tokens)
{
	check_pipes(&(*tokens));
	check_redir_err(&(*tokens));
	if (g_data.syntax_error == -1)
		ft_error("minishell: syntax error near unexpected token `\"'\n", 2);
	else if (g_data.syntax_error == -2)
		ft_error("minishell: syntax error near unexpected token `\''\n", 2);
	else if (g_data.syntax_error == -3)
		ft_error("minishell: syntax error near unexpected token `|'\n", 2);
	else if (g_data.syntax_error == -4)
		ft_error("minishell: syntax error near unexpected token `newline'\n",
			2);
	else if (g_data.syntax_error == -5)
		ft_error("minishell: syntax error near unexpected token \n", 2);
}

void	check_pipes(t_item **tokens)
{
	t_item	*tmp;

	tmp = *tokens;
	tmp = tmp->next;
	if (tmp->type == PIPE && tmp->state == GENERAL)
		return ((void)(g_data.syntax_error = -3));
	while (tmp)
	{
		if (tmp->type == PIPE && tmp->state == GENERAL && !tmp->next->content)
			return ((void)(g_data.syntax_error = -3));
		else if (tmp->type == PIPE && tmp->state == GENERAL
			&& tmp->next->type != WORD && tmp->next->state == GENERAL
			&& tmp->next->next->type != WORD)
			return ((void)(g_data.syntax_error = -3));
		else if (tmp->type == PIPE && tmp->state == GENERAL
			&& tmp->next->type == PIPE && tmp->next->state == GENERAL)
			return ((void)(g_data.syntax_error = -3));
		tmp = tmp->next;
	}
}

void	check_end_quots(t_item **tokens)
{
	t_item	*tmp;

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
