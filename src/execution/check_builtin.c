#include "execution.h"

void	builtins(t_global *global, char **args)
{
	char	*command = args[0];

	if (ft_strncmp("export", command, ft_strlen("export")) == 0)
		ft_export(t_list *p, t_data **data, t_info *info)
	if (ft_strncmp("env", command, ft_strlen("env")) == 0)
		print_env(global);
	if (ft_strncmp("unset", command, ft_strlen("unset")) == 0)
		unset(global, &global->env, &global->export, args + 1);
	if (ft_strncmp("exit", command, ft_strlen("exit")) == 0)
		exitt(global, args + 1);
	if (ft_strncmp("pwd", command, ft_strlen("pwd")) == 0)
		pwd(global);
	if (ft_strncmp("cd", command, ft_strlen("cd")) == 0)
		cd(global, args + 1, global->export);
	if (ft_strncmp("echo", command, ft_strlen("echo")) == 0)
		echo(global, args + 1);
}


int	is_builtin(char *token)
{
	if (!ft_strcmp(token, "echo"))
		return (1);
	else if (!ft_strcmp(token, "cd"))
		return (1);
	else if (!ft_strcmp(token, "pwd"))
		return (1);
	else if (!ft_strcmp(token, "env"))
		return (1);
	else if (!ft_strcmp(token, "export"))
		return (1);
	else if (!ft_strcmp(token, "unset"))
		return (1);
	else if (!ft_strcmp(token, "exit"))
		return (1);
	return (0);
}
