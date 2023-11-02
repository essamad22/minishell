#include "minishell.h"

char	*getz(void)
{
	char	*s;

	s = getcwd(NULL, 0);
	return (s);
}

char	*getpwd(void)
{
	char	*tmp;
	char	*path;
	char	s[1024];
	char	*buff;

	tmp = getcwd(s, sizeof(s));
	if (tmp)
	{
		buff = ft_strdup(tmp);
		return (buff);
	}
	else
	{
		path = getenv("PWD");
		if (path != NULL)
			return (path);
	}
	return (NULL);
}