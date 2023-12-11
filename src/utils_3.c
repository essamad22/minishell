/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhtab <aakhtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 13:32:30 by aakhtab           #+#    #+#             */
/*   Updated: 2023/11/12 13:38:29 by aakhtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	free_vr(t_vr *vr)
{
	int	i;

	i = 0;
	while (i < vr->envlen)
		free(vr->env[i++]);
	free(vr->env);
	free(vr);
}

void	clear_data(t_cmd_tab **tmp)
{
	t_cmd_tab	*tmp2;

	while ((*tmp))
	{
		ft_free_2d((*tmp)->cmd);
		if ((*tmp)->redirs)
			free_redir(&(*tmp)->redirs);
		if ((*tmp)->file)
			free_file(&(*tmp)->file);
		tmp2 = (*tmp);
		(*tmp) = (*tmp)->next;
		free(tmp2);
	}
	free(*tmp);
}
