
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

	env = ft_split(ft_getpath(envp), ':');
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

	i = 0;
	res = 1;
	while (env[i] && res != 0)
	{
		env[i] = ft_strjoin1(env[i], "/");
		check = ft_strjoin1(env[i], cmd);
		res = access(check, X_OK);
		i++;
	}	
	return (check);
}
