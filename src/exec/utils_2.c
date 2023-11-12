/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasrollahkhachabi <nasrollahkhachabi@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 03:48:19 by aakhtab           #+#    #+#             */
/*   Updated: 2023/11/12 22:29:14 by nasrollahkh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_exitstatus(int status)
{
	int	exitstatus;

	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	if (WIFSIGNALED(status))
	{
		exitstatus = WTERMSIG(status);
		return (exitstatus + 128);
	}
	return (0);
}

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
			g_data.exit_status = ft_exitstatus(v->status);
		v->tmp = v->tmp->next;
		v->i++;
	}
	free(exec->p);
	free (exec);
}

char	*remove_plus(char *word)
{
	char	*new_word;
	int		i;
	int		j;

	new_word = malloc(ft_strlen(word));
	i = 0;
	j = 0;
	while (word[i])
	{
		if (word[i] == '+' && word[i + 1] && word[i + 1] == '=')
		{
			i++;
			continue ;
		}
		new_word[j++] = word[i];
		i++;
	}
	new_word[j] = '\0';
	return (new_word);
}

void	process_env_var(t_vr *vr, char *cmd)
{
	char	*tmp22;

	tmp22 = remove_plus(cmd);
	vr->env = add_to_export(vr->env, tmp22);
	add_env(&g_data.env_lst, new_env(tmp22));
	free(tmp22);
	vr->envlen++;
}
