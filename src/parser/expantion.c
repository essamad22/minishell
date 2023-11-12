/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expantion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhtab <aakhtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 10:46:02 by aakhtab           #+#    #+#             */
/*   Updated: 2023/11/12 13:26:40 by aakhtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	expand(t_item **tokens)
{
	t_env_list	*env_lst;

	if ((*tokens)->prev && (*tokens)->prev->type == HEREDOC)
	{
		(*tokens)->type = WORD;
		return (0);
	}
	if ((*tokens)->content[0] == '$' && (*tokens)->content[1] == '?')
	{
		free((*tokens)->content);
		(*tokens)->content = ft_itoa(g_data.exit_status);
		(*tokens)->len = ft_strlen((*tokens)->content);
		(*tokens)->type = WORD;
		return (0);
	}
	env_lst = get_var((*tokens), g_data.env_lst);
	return (fill_env(&(*tokens), env_lst));
}

int	fill_env(t_item **tokens, t_env_list *env)
{
	if (!env)
	{
		free((*tokens)->content);
		(*tokens)->content = ft_strdup("");
		(*tokens)->len = ft_strlen((*tokens)->content);
		(*tokens)->type = WORD;
		if ((*tokens)->state != IN_DQUOTE)
			return (1);
	}
	else
	{
		free((*tokens)->content);
		(*tokens)->content = ft_strdup(env->value);
		(*tokens)->len = ft_strlen((*tokens)->content);
		(*tokens)->type = WORD;
		if (strchr((*tokens)->content, ' ') && (*tokens)->state != IN_DQUOTE)
			return (1);
	}
	return (0);
}
