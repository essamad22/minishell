/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhtab <aakhtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 00:38:44 by aakhtab           #+#    #+#             */
/*   Updated: 2023/11/12 13:34:44 by aakhtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*lexer_heredoc(char *hd_line)
{
	t_item	*head;
	t_item	*tmp;
	int		stat;
	int		i;

	head = new_item(NULL, 0, WORD, GENERAL);
	stat = GENERAL;
	i = 0;
	while (hd_line[i])
		i += get_token_hd(&head, hd_line + i, &stat);
	tmp = head;
	while (tmp)
	{
		if (tmp->type == ENV)
			expand(&tmp);
		tmp = tmp->next;
	}
	join_after_expand(&head);
	tmp = head;
	head = head->next;
	rm_item(&tmp);
	hd_line = ft_strdup(head->content);
	rm_item(&head);
	return (hd_line);
}

int	get_token_hd(t_item **list, char *cmd_line, int *stat)
{
	if (*cmd_line == ENV)
		return (env(list, cmd_line, stat));
	else
		return (word_hd(list, cmd_line, stat));
}

int	word_hd(t_item **list, char *cmd_line, int *stat)
{
	int	i;

	i = -1;
	while (cmd_line[++i])
		if (cmd_line[i] == ENV)
			break ;
	add_item(list, new_item(ft_substr(cmd_line, 0, i), i, WORD, *stat));
	return (i);
}

void	join_after_expand(t_item **tokens)
{
	t_item	*tmp;
	t_item	*holder;

	tmp = *tokens;
	while (tmp)
	{
		tmp = tmp->next;
		while (tmp->next)
		{
			tmp->content = ft_strjoin(tmp->content, tmp->next->content);
			tmp->len = ft_strlen(tmp->content);
			holder = tmp->next;
			rm_item(&holder);
		}
		tmp->type = WORD;
		tmp = tmp->next;
	}
}
