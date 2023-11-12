/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utls.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhtab <aakhtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 03:47:42 by aakhtab           #+#    #+#             */
/*   Updated: 2023/11/12 13:11:08 by aakhtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_getpath(char **envp)
{
	char	*path;
	int		i;

	i = 0;
	path = NULL;
	while (envp[i] && !path)
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			path = envp[i];
		i++;
	}
	if (!path)
	{
		ft_error("minishell : No such file or directory\n", 127);
		exit (127);
	}
	return (ft_substr(path, 5, ft_strlen(path) - 5));
}

char	**get_path_splited(char **envp)
{
	char	**env;
	char	*path;

	path = ft_getpath(envp);
	env = ft_split(path, ':');
	free(path);
	if (!env)
	{
		ft_error("minishell : No such file or directory\n", 127);
		exit (127);
	}
	return (env);
}

char	*ft_checkaccess(char *cmd, char **env)
{
	int		res;
	int		i;
	char	*check;
	char	*tmp;

	i = 0;
	res = 1;
	while (env[i] && res != 0)
	{
		tmp = ft_strjoin(env[i], "/");
		free(env[i]);
		env[i] = tmp;
		check = ft_strjoin(env[i], cmd);
		res = access(check, X_OK);
		if (res == 0)
			return (check);
		free(check);
		i++;
	}
	return (NULL);
}
