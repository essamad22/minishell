/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhtab <aakhtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 17:35:01 by aakhtab           #+#    #+#             */
/*   Updated: 2023/11/12 13:34:10 by aakhtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	**ft_envdup(char **env)
{
	char	**env_dup;
	int		i;
	int		len;

	i = -1;
	len = strlen_2d(env);
	env_dup = (char **)malloc(sizeof(char *) * (len + 1));
	if (!env_dup)
		return (NULL);
	while (env[++i])
	{
		env_dup[i] = ft_strdup(env[i]);
		if (!env_dup[i])
			return (NULL);
	}
	return (env_dup);
}

t_env_list	*ft_envlst(char **env)
{
	t_env_list	*env_lst;
	int			i;
	int			len;

	env_lst = NULL;
	i = -1;
	len = strlen_2d(env);
	while (++i < len)
		add_env(&env_lst, new_env(env[i]));
	return (env_lst);
}

t_env_list	*new_env(char *env)
{
	t_env_list	*new;
	int			len;
	int			i;

	i = -1;
	new = (t_env_list *)malloc(sizeof(t_env_list));
	len = ft_strlen(env);
	while (++i < len)
		if (env[i] == '=')
			break ;
	new->name = ft_substr(env, 0, i);
	new->value = ft_substr(env, i + 1, len - i);
	new->next = NULL;
	return (new);
}

void	add_env(t_env_list **env_lst, t_env_list *new)
{
	t_env_list	*tmp;

	tmp = *env_lst;
	if (tmp == NULL)
	{
		(*env_lst) = new;
		return ;
	}
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}
