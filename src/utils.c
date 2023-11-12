/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhtab <aakhtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 17:32:16 by aakhtab           #+#    #+#             */
/*   Updated: 2023/11/12 13:33:56 by aakhtab          ###   ########.fr       */
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

void	free_redir(t_redir **redir)
{
	t_redir	*tmp;

	while ((*redir))
	{
		if ((*redir)->redirect)
			free((*redir)->redirect);
		tmp = (*redir);
		(*redir) = (*redir)->next;
		free(tmp);
	}
	free(*redir);
}

void	free_file(t_file **file)
{
	t_file	*tmp;

	while ((*file))
	{
		if ((*file)->file_name)
			free((*file)->file_name);
		tmp = (*file);
		(*file) = (*file)->next;
		free(tmp);
	}
	free(*file);
}
