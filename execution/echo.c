#include "minishell.h"

int check_option(char *s)
{
	int j;

	j = 2;
	if (s[0] == '-' && s[1] == 'n')
	{
		if (strcmp(s, "-n") == 0)
			return (0);
		while (s[j])
		{
			if (s[j] != 'n')
				return (1);
			j++;
		}
		return (0);
	}
	return (1);
}

int ft_norm(char **all_cmds)
{
	int i;

	i = 1;
	while (all_cmds[i])
	{
		if (check_option(all_cmds[i]) == 0)
			i++;
		else
			break;
	}
	return (i);
}

void norm_echo(char **all_cmds, int k, int fd, int fdd)
{
	int i;

	i = ft_norm(all_cmds);
	while (all_cmds[i])
	{
		if (fdd > 0)
		{
			write(fdd, all_cmds[i], strlen(all_cmds[i]));
			if (all_cmds[i + 1] != NULL)
				write(fdd, " ", 2);
		}
		else if (k == 0)
		{
			write(fd, all_cmds[i], strlen(all_cmds[i]));
			if (all_cmds[i + 1] != NULL)
				write(fd, " ", 2);
		}
		else
		{
			write(1, all_cmds[i], strlen(all_cmds[i]));
			if (all_cmds[i + 1] != NULL)
				write(1, " ", 2);
		}
		i++;
	}
}

void print_echo(char **all_cmds, int k, int fd, int fdd)
{
	if (fdd > 0)
	{
		if (check_option(all_cmds[1]) != 0)
			write(fdd, "\n", 1);
	}
	else if (k == 0)
	{
		if (check_option(all_cmds[1]) != 0)
			write(fd, "\n", 1);
	}
	else
	{
		if (check_option(all_cmds[1]) != 0)
			write(1, "\n", 1);
	}
}

void __echo__(char **all_cmds, int k, int fd, int fdd)
{
	if (all_cmds[1] == NULL)
	{
		if (fdd > 0)
			write(fdd, "\n", 1);
		if (k == 0)
			write(fd, "\n", 1);
		else
			write(1, "\n", 1);
		return;
	}
	norm_echo(all_cmds, k, fd, fdd);
	print_echo(all_cmds, k, fd, fdd);
}

int main(int argc, char **argv)
{
    (void)argc;
	int k = 0; // mettre la valeur appropriée pour k
	int fd = 1; // mettre la valeur appropriée pour fd
	int fdd = 0; // mettre la valeur appropriée pour fdd

	__echo__(argv, k, fd, fdd);
	return 0;
}
