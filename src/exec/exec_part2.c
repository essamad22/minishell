
#include "../../includes/minishell.h"

int	*out_file(t_file *file,	int *fd)
{
	if (file->type == 2)
	{
		fd[1] = open(file->file_name, O_RDWR | O_CREAT | O_TRUNC, 0644);
		if (fd[1] < 0)
		{
			ft_error("minishell: No such file or directory\n", 1);
			return (NULL);
		}
	}
	if (file->type == 4)
	{
		fd[1] = open(file->file_name, O_RDWR | O_CREAT | O_APPEND, 0644);
		if (fd[1] < 0)
		{
			ft_error("minishell: No such file or directory\n", 1);
			return (NULL);
		}
	}
	return (fd);
}

int	*openfile_ut(t_file *file,	int *fd)
{
	fd = out_file(file, fd);
	if (file->type == 3)
	{
		fd[0] = open(file->file_name, O_RDONLY, 0644);
		if (fd[0] < 0)
		{
			ft_error("minishell: No such file or directory\n", 1);
			return (NULL);
		}
	}
	if (file->type == 5 && g_data.exitheredoc != 1)
		fd[0] = heredoc(file->file_name);
	return (fd);
}

int	*openfile(t_cmd_tab *list)
{
	int		*fd;
	t_cmd_tab	*tmp;
	t_file	*fl;

	tmp = list;
	fl = tmp->file;
	fd = malloc(sizeof(int) * 2);
	fd[0] = 0;
	fd[1] = 0;
	while (fl)
	{
		fd = openfile_ut(fl, fd);
		if (!fd)
			return (NULL);
		fl = fl->next;
	}
	return (fd);
}

void	ft_execve(t_cmd_tab *list, t_vr *vr, char *cmderr)
{
	if (!in_builtin(list))
	{	
		if (execve(list->cmd[0], list->cmd, vr->env) < 0)
		{
			ft_error(ft_strjoin1(ft_strjoin1("minishell : ", cmderr),
					" :command not found\n"), 127);
			free (cmderr);
			exit (127);
		}
	}
}
