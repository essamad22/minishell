/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhachab <nkhachab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 03:48:19 by aakhtab           #+#    #+#             */
/*   Updated: 2023/11/12 09:56:07 by nkhachab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	closepipe_andwait(t_exec_p *exec, t_v *v)
{
	v->i = 0;
	while (v->i < v->is_pipe * 2)
		close(exec->p[v->i++]);
	v->i = 0;
	while (v->i < v->is_pipe)
	{
		waitpid(0, &v->status, 0);
		if (!in_builtin(v->tmp))
			g_data.exit_status = WEXITSTATUS(v->status);
		v->tmp = v->tmp->next;
		v->i++;
	}
	free(exec->p);
	free (exec);
}
