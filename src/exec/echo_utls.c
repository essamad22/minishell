
#include "../../includes/minishell.h"

void	print_n_echo(char **cmd, int fd, int i)
{
	while (cmd[i])
	{
		ft_putstr_fd(cmd[i++], fd);
		if (cmd[i])
			ft_putchar_fd(' ', fd);
	}
}
