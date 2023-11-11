/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhtab <aakhtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 17:32:16 by aakhtab           #+#    #+#             */
/*   Updated: 2023/11/11 23:56:41 by aakhtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_isenv(int c)
{
	if (ft_isalnum(c))
		return (1);
	if (c == '_' || c == '?')
		return (1);
	else
		return (0);
}

int	strlen_2d(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_free_2d(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

// void    clear_data(t_cmd_tab **tmp)
// {
//     t_cmd_tab *tmp2;
//     while ((*tmp))
//     {
//         ft_free_2d((*tmp)->cmd);
//         if ((*tmp)->redirs)
//             free_redir(&(*tmp)->redirs);
//         tmp2 = (*tmp);
//         (*tmp) = (*tmp)->next;
//         free(tmp2);
//     }
//     free(*tmp);
// }

int	len_of_cmd(t_item *token)
{
	int	len;

	len = 0;
	if (!token)
		return (0);
	while (token)
	{
		if (token->type == WORD && (token->state == GENERAL
				|| token->state == IN_QUOTE || token->state == IN_DQUOTE))
			len++;
		token = token->next;
	}
	return (len);
}

void	free_redir(t_redir **redir)
{
	t_redir	*tmp;

	while ((*redir))
	{
		free((*redir)->redirect);
		tmp = (*redir);
		(*redir) = (*redir)->next;
		free(tmp);
	}
	free(*redir);
}
