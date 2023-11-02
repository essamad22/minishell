#include "execution.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return (ft_putchar_fd(0, fd));
	while (*s)
	{
		ft_putchar_fd(*s, fd);
		s++;
	}
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)s + i);
	return (NULL);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	if (!s1 || !s2)
		return (0);
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while ((str1[i] || str2[i]))
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

int	ft_strlen1(const char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*ret;

	ret = (char *)malloc(ft_strlen1(s1) + 1);
	if (!ret)
		return (0);
	i = 0;
	while (s1[i])
	{
		ret[i] = s1[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

void	add_to_env(t_env **env, char *var, char *value)
{
	t_env	*new;
	t_env	*tmp;

	new = malloc(sizeof(t_env));
	if (!new)
	{
		printf("Error en");
	}
	new->var = var;
	new->value = value;
	new->next = NULL;
	new->prev = NULL;
	if (!*env)
	{
		*env = new;
		return ;
	}
	tmp = *env;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	new->prev = tmp;
}

size_t	find_equale(char *str)
{
	size_t	count;

	count = 0;
	while (str[count] && str[count] != '=')
		count++;
	return (count);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*s1;
	char	*sa;

	s1 = (char *)s;
	i = 0;
	if (!s1)
		return (0);
	if ((int)start >= ft_strlen1((char *)s1))
		return (ft_strdup("\0"));
	if (len > ft_strlen1(s1) - start)
		len = ft_strlen1(s1) - start;
	sa = malloc(sizeof(char) *(len + 1));
	if (!sa)
		return (0);
	while (i < len && s1[i] != '\0')
	{
		sa[i++] = s1[start++];
	}
	sa[i] = '\0';
	return (sa);
}



t_env	*create_env(char **envp)
{
	t_env	*env;

	env = NULL;
	while (*envp)
	{
		add_to_env(&env, ft_substr(*envp, 0, find_equale(*envp)), \
		ft_strdup(ft_strchr(*envp, '=') + 1));
		envp++;
	}
	return (env);
}

void	print_env(t_global *global)
{
	t_env	*tmp_env;

	tmp_env = global->env;

	while (tmp_env)
	{
		if (ft_strcmp(tmp_env->var, "PATH") == 0)
		{
			while (tmp_env)
			{
				ft_putstr_fd(tmp_env->var, 1);
				ft_putstr_fd("=", 1);
				ft_putstr_fd(tmp_env->value, 1);
				ft_putstr_fd("\n", 1);
				tmp_env = tmp_env->next;
			}
			return ;
		}
		tmp_env = tmp_env->next;
	}
	if (!tmp_env)
		ft_putstr_fd("minishell: env: No such file or directory\n", 2);
}


int main(int argc, char *argv[], char **env) {
    t_global global;  // Initialise t_global

	global.env = create_env(env);
    if (argc == 2 && ft_strcmp(argv[1], "env") == 0) {
        print_env(&global);
    } else {
        // Autre traitement ou affichage d'un message d'erreur si nécessaire
        ft_putstr_fd("Usage: ./ton_programme env\n", 2);
    }

    return 0;
}