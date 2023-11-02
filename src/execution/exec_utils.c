#include "execution.h"

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

char	*ft_strjoin10(char *s1, char *s2)
{
	char	*p;
	int		i;
	int		j;

	if (!s1 && !s2)
		return (NULL);
	p = (char *)malloc(ft_strlen1(s1) + ft_strlen1(s2) + 1);
	if (!p)
		return (NULL);
	i = -1;
	while (s1 && s1[++i])
	{
		if (i <= ft_strlen1(s1))
			p[i] = s1[i];
	}
	j = -1;
	while (s2 && s2[++j])
	{
		if (i < ft_strlen1(s1) + ft_strlen1(s2))
			p[i] = s2[j];
		i++;
	}
	p[i] = '\0';
	free(s1);
	return (p);
}

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

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	printerr(char *s1, char *s2, char *s3)
{
	ft_putstr_fd(s1, 2);
	ft_putstr_fd(": ", 2);
	if (s2)
	{
		ft_putstr_fd(s2, 2);
		ft_putstr_fd(": ", 2);
	}
	if (s3)
	{
		ft_putstr_fd(s3, 2);
		ft_putchar_fd('\n', 2);
	}
}

char	*ft_strjoin1(char *s1, char *s2)
{
	char	*p;
	int		i;
	int		mid;

	if (!s1 || !s2)
		return (0);
	i = 0;
	while (s1[i] && s1[i] != '=')
		i++;
	p = (char *)malloc(sizeof(char) * (i + ft_strlen(s2) + 2));
	if (!p)
		return (NULL);
	i = -1;
	while (s1[++i] && s1[i] != '=')
		p[i] = s1[i];
	p[i++] = '=';
	mid = 0;
	while (s2[mid])
	{
		p[mid + i] = s2[mid];
		mid++;
	}
	p[mid + i] = '\0';
	free(s1);
	return (p);
}

int	checktossawiplace(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '=')
			return (i);
		i++;
	}
	return (0);
}

char	*bringbeforetossawi(char *s)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	i = checktossawiplace(s);
	if (i == 0)
		return (NULL);
	str = malloc(i + 1);
	i = 0;
	while (s[i] != '=')
	{
		str[i] = s[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}

char	*bringaftertossawi(char *s)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (s[i])
		i++;
	while (s[j] != '=')
		j++;
	str = malloc(i - j);
	j++;
	i = 0;
	while (s[j])
	{
		str[i] = s[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while ((str1[i] || str2[i]) && i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}