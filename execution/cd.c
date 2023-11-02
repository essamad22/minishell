#include "minishell.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*p;
	int		len;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen1((char *)s1) + ft_strlen1((char *)s2);
	p = malloc(sizeof(char) * (len + 1));
	if (!p)
		return (NULL);
	while ((size_t)i < ft_strlen((char *)s1))
	{
		p[i] = s1[i];
		i++;
	}
	j = 0;
	while (i < len)
		p[i++] = s2[j++];
	p[i] = '\0';
	return (p);
}


void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*str;
	size_t			i;

	str = b;
	i = 0;
	while (i < len)
	{
		str [i] = (unsigned char)c;
		i++;
	}
	return (b);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, size * count);
	return (ptr);
}

char	*getmyenv(char *s, t_data **env)
{
	t_data	*tmp;
	char	*str;

	if (!(*env)->content)
		return (NULL);
	tmp = *env;
	str = ft_calloc(1, 1);
	while (tmp)
	{
		if (ft_strncmp(s, tmp->content, ft_strlen(s)) == 0)
		{
			str = ft_strjoin10(str, tmp->content + ft_strlen(s) + 1);
			break ;
		}
		tmp = tmp->next;
	}
	if (!tmp)
	{
		free(str);
		return (NULL);
	}
	return (str);
}

char	*getsecondlast(char *s)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (s[i])
		i++;
	i -= 1;
	while (i > 0 && s[i] != '/')
		i--;
	str = malloc(i + 1);
	while (j < i)
	{
		str[j] = s[j];
		j++;
	}
	str[j] = '\0';
	return (str);
}

char	*helper(char *s)
{
	char	*s1;
	char	*s2;

	s1 = s;
	s2 = getpwd();
	s = ft_strjoin("PWD=", s2);
	(free(s1), free(s2));
	return (s);
}

void	chengingoldpwd(char *s, t_data **data)
{
	t_data	*tmp;
	int		count;
	char	*s1;

	count = 0;
	tmp = *data;
	while (tmp)
	{
		if (ft_strncmp(tmp->content, "OLDPWD", 6) == 0)
		{
			s1 = tmp->content;
			tmp->content = ft_strjoin("OLDPWD=", s);
			free(s1);
			count++;
		}
		else if (ft_strncmp(tmp->content, "PWD=", 4) == 0)
		{
			tmp->content = helper(tmp->content);
			count++;
		}
		if (count == 2)
			break ;
		tmp = tmp->next;
	}
}

int	whdfnccd(t_data **data)
{
	char	*oldpwd;

	oldpwd = getpwd();
	chdir("..");
	if ((*data)->content)
		chengingoldpwd(oldpwd, data);
	free(oldpwd);
	return (1);
}


int	noarg(t_list *p, t_data **data)
{
	char	*oldpwd;
	char	*home;

	oldpwd = getpwd();
	home = getmyenv("HOME", data);
	if (!home)
	{
		free(oldpwd);
		printerr("bash", p->commandes[0], "HOME not set");
		return (0);
	}
	chdir(home);
	chengingoldpwd(oldpwd, data);
	free(home);
	free(oldpwd);
	return (1);
}

int	whdfnccd100(t_list *p, t_data **data)
{
	char	*oldpwd;
	int		dir;

	dir = 0;
	oldpwd = getpwd();
	chengingoldpwd(oldpwd, data);
	dir = chdir(p->commandes[1]);
	if (dir == -1)
	{
		printerr(p->commandes[0], p->commandes[1], "No such file or directory");
		free(oldpwd);
		return (1);
	}
	free(oldpwd);
	return (1);
}



int	ft_cd(t_list *p, t_data **data)
{
	char	*oldpwd;

	if (ft_strcmp(p->commandes[0], "CD") == 0)
		return (0);
	if (p->commandes[1] == NULL)
		return (noarg(p, data));
	else
	{
		if (ft_strncmp(".", p->commandes[1], 1) == 0 && p->commandes[1][1] == '\0')
		{
			oldpwd = getz();
			if (!oldpwd)
				ft_putstr_fd("cd: error retrieving current directory: \
					getcwd: cannot access\
					parent directories: No such file or directory\n", 2);
			else
				free(oldpwd);
			return (1);
		}
		else if (ft_strncmp("..", p->commandes[1], 2) == 0 && p->commandes[1][2] == '\0')
			return (whdfnccd(data));
		else
			return (whdfnccd100(p, data));
	}
	return (0);
}