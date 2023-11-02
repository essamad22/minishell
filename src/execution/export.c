#include "execution.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	i;

	str = malloc(sizeof(char) * (ft_strlen((char *)s1) + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
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

// void	printerr(char *s1, char *s2, char *s3)
// {
// 	ft_putstr_fd(s1, 2);
// 	ft_putstr_fd(": ", 2);
// 	if (s2)
// 	{
// 		ft_putstr_fd(s2, 2);
// 		ft_putstr_fd(": ", 2);
// 	}
// 	if (s3)
// 	{
// 		ft_putstr_fd(s3, 2);
// 		ft_putchar_fd('\n', 2);
// 	}
// }

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





int	strlenhtal(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '=')
		i++;
	return (i);
}
void	printerr1(char *s1, char *s2, char *s3)
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
	// g_globe.exit_status = 1;
}

// int	ft_isdigit(int c)
// {
// 	if (c >= '0' && c <= '9')
// 		return (1);
// 	return (0);
// }
int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	return (0);
}
int	chekspecial(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (!(ft_isalpha(s[i])) && !(ft_isdigit(s[i])) && s[i] != '_'
			&& (s[i] != '=') && (s[i] != '+'))
			return (0);
		i++;
	}
	return (1);
}
int	checkingifexist1(char *s, t_data **data, int l)
{
	t_data	*tmp;

	tmp = *data;
	while (tmp)
	{
		if (ft_strncmp(tmp->content, s, l) == 0)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}







char	*withoutp(char *s)
{
	char	*str;
	int		j;
	int		i;

	j = 0;
	i = 0;
	while (s[i] != '+')
		i++;
	str = malloc(i + 1);
	while (j < i)
	{
		str[j] = s[j];
		j++;
	}
	str[j] = '\0';
	str = ft_strjoin10(str, s + i + 1);
	return (str);
}
int	help_exp(char *s, int flag)
{
	int	i;

	i = 0;
	if (!ft_isalpha(s[0]) && s[0] != '_')
	{
		if (flag == 0)
			free(s);
		return (1);
	}
	while (s[i])
	{
		if (!(ft_isalpha(s[i])) && !(ft_isdigit(s[i])) && s[i] != '_'
			&& (s[i] != '='))
		{
			if (flag == 0)
				free(s);
			return (1);
		}
		i++;
	}
	return (0);
}
int	checkchar(char *str)
{
	// int		i;
	char	*s;
	int		flag;

	flag = 0;
	// i = 0;
	s = bringbeforetossawi(str);
	if (s == NULL)
	{
		(s = str);
		(flag = 1);
	}
	if (help_exp(s, flag))
		return (1);
	if (flag == 0)
		free(s);
	return (0);
}

int	ecrase(char *s, t_data **data, int *check)
{
	t_data	*tmp;
	char	*str;

	tmp = *data;
	str = bringaftertossawi(s);
	while (tmp)
	{
		if (ft_strncmp(tmp->content, s, *check) == 0
			&& ((ft_strncmp(tmp->content + *check, "=", 1) == 0)
				|| !(tmp->content[*check])))
		{
			tmp->content = ft_strjoin1(tmp->content, str);
			free(str);
			return (0);
		}
		tmp = tmp->next;
	}
	free(str);
	return (1);
}
int	checkingifexist(char *s, t_data **data)
{
	t_data	*tmp;
	char	*str;
	int		len;

	len = 0;
	str = bringbeforetossawi(s);
	tmp = *data;
	if (!(tmp))
		return (1);
	while (tmp)
	{
		if (!str)
			len = ft_strlen1(s);
		else
			len = ft_strlen1(str);
		if (ft_strncmp(tmp->content, s, len) == 0
			&& strlenhtal(tmp->content) == ft_strlen1(s))
		{
			free(str);
			return (0);
		}
		tmp = tmp->next;
	}
	free(str);
	return (1);
}

t_data	*ft_lstlast(t_data *lst)
{
	while (lst != NULL && lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back1(t_data **lst, t_data *new)
{
	t_data	*addl;

	addl = 0;
	if (*lst == NULL)
	{
		new->next = NULL;
		*lst = new;
	}
	else
	{
		addl = ft_lstlast(*lst);
		addl->next = new;
	}
}

t_data	*ft_lstnew1(void *content)
{
	t_data	*new;

	new = (t_data *)malloc(sizeof(t_data));
	if (!new)
		return (NULL);
	new->content = ft_strdup((char *)content);
	new->next = NULL;
	return (new);
}

void	export_1(t_data **data, char *s, int *check1, int *i)
{
	if (checkchar(s) == 1)
		printerr1("export", s, "not a valid identifier");
	else if (checkingifexist1(s, data, *check1) == 0)
	{
		if (ecrase(s, data, check1) == 1)
			ft_lstadd_back1(data, ft_lstnew1(s));
		// g_globe.exit_status = 0;
	}
	else if (checkingifexist(s, data) == 0)
	{
		(*i)++;
		// g_globe.exit_status = 0;
	}
	else
	{
		ft_lstadd_back1(data, ft_lstnew1(s));
		// g_globe.exit_status = 0;
	}
}
int	checkzaid(char *s)
{
	int		i;
	int		len;
	char	*str;

	str = bringbeforetossawi(s);
	if (!str)
		len = 0;
	else
	{
		len = ft_strlen(str);
		free(str);
	}
	i = 0;
	while (s[i])
	{
		if (s[i] == '+')
		{
			if (s[i + 1] == '=')
				return (i);
			else if (i < len)
				return (-1);
		}
		i++;
	}
	return (0);
}

int	free_export(char *s, int i)
{
	free(s);
	return (i);
}
int	checknotexist(char *s, t_data **data, int len)
{
	t_data	*tmp;
	char	*str;

	len = 0;
	str = bringbeforetossawi(s);
	tmp = *data;
	while (tmp)
	{
		if (!str)
			len = ft_strlen(s);
		else
		{
			if (checkzaid(s) != 0)
				len = ft_strlen(str) - 1;
			else
				len = ft_strlen(str);
		}
		if (ft_strncmp(tmp->content, s, len) == 0)
			return (free_export(str, 0));
		tmp = tmp->next;
	}
	return (free_export(str, -1));
}
void	smt(int *i, int *check, int *flag)
{
	ft_putchar_fd('=', 1);
	if (*flag == 0)
		ft_putchar_fd('"', 1);
	(*i)++;
	*check = 1;
	*flag = 1;
}
void	checktossawiwzid(char *s)
{
	int	i;
	int	check;
	int	flag;

	i = 0;
	check = 0;
	flag = 0;
	ft_putstr_fd("declare -x ", 1);
	while (s[i])
	{
		if (s[i] != '=')
			ft_putchar_fd(s[i++], 1);
		else
			smt(&i, &check, &flag);
	}
	if (s[i] == '\0' && check == 1)
		ft_putchar_fd('"', 1);
	ft_putchar_fd('\n', 1);
}
int	checktossawi(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '=')
			return (0);
		i++;
	}
	return (1);
}
void	joining(char *s, t_data **data, int *check)
{
	t_data	*tmp;
	char	*str;

	tmp = *data;
	str = bringaftertossawi(s);
	while (tmp)
	{
		if (ft_strncmp(tmp->content, s, *check) == 0
			&& (tmp->content[*check] == '=' || tmp->content[*check] == '\0'))
		{
			if (!checktossawi(tmp->content))
				tmp->content = ft_strjoin10(tmp->content, str);
			else
			{
				tmp->content = ft_strjoin1(tmp->content, "=");
				tmp->content = ft_strjoin1(tmp->content, str);
			}
		}
		tmp = tmp->next;
	}
	free(str);
}

void	export_2(t_data **data, char *s, int *check)
{
	char	*str;

	if (checknotexist(s, data, *check) == -1)
	{
		
		str = withoutp(s);
		ft_lstadd_back1(data, ft_lstnew1(str));
		// g_globe.exit_status = 0;
		free(str);
	}
	else
	{
		joining(s, data, check);
		// g_globe.exit_status = 0;
	}
}

void	iniiiit(t_info *info)
{
	info->check = 0;
	info->check1 = 0;
	info->i_exp = 1;
}

int	checkchar1(char *s)
{
	int	i;

	i = 0;
	if (s[0] == '+')
		return (0);
	while (s[i])
	{
		if (!(ft_isalpha(s[i])) && !(ft_isdigit(s[i])) && s[i] != '_'
			&& ((s[i] == '=') && ft_strlen(s) != 1))
			return (1);
		i++;
	}
	return (0);
}








int	returntossawi(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '=')
			return (i);
		i++;
	}
	return (-1);
}














void	printenvwithx(t_data **data)
{
	t_data	*tmp;

	tmp = *data;
	while (tmp)
	{
		checktossawiwzid(tmp->content);
		tmp = tmp->next;
	}
}

void	iniiiit1(t_info *info, char *s)
{
	info->check = checkzaid(s);
	info->check1 = checktossawiplace(s);
}

int	export_3(t_data **data, char *s)
{
	if (!s[0])
	{
		printerr1("export", s, "not a valid identifier");
		return (1);
	}
	else if (checkingifexist(s, data) == 0)
	{
		// g_globe.exit_status = 0;
		return (1);
	}
	else
	{
		if (checkchar(s) == 1)
		{
			printerr1("export", s, "not a valid identifier");
			return (1);
		}
		else
		{
			ft_lstadd_back1(data, ft_lstnew1(s));
			// g_globe.exit_status = 0;
		}
	}
	return (0);
}

void	export_4(t_data **data, t_list *p, t_info *info)
{
	while (p->commandes[info->i_exp])
	{
		iniiiit1(info, p->commandes[info->i_exp]);
		if (info->check == 0 && checktossawi(p->commandes[info->i_exp]) == 1)
		{
			
			if (export_3(data, p->commandes[info->i_exp]) == 1)
			{
				info->i_exp++;
				continue ;
			}
		}
		else if (info->check == -1)
		{
			
			if (checkchar(p->commandes[info->i_exp]) == 1)
			{
				printerr1(p->commandes[0], p->commandes[info->i_exp],
					"not a valid identifier");
			}
		}
		else if (info->check == 0 && checktossawi(p->commandes[info->i_exp]) == 0)
		{
			
			export_1(data, p->commandes[info->i_exp], &info->check1, &info->i_exp);
		}
		else if (info->check != 0 && info->check != -1)
		{
			
			export_2(data, p->commandes[info->i_exp], &info->check);

		}
		info->i_exp++;
	}
}

int	ft_lstsize(t_data *lst)
{
	int	total;

	total = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		total++;
	}
	return (total);
}



t_data	*sort_list(t_data *lst)
{
	char	*swap;
	t_data	*tmp;

	tmp = lst;
	if (ft_lstsize(tmp) < 1)
		return (lst);
	while (lst->next != NULL)
	{
		if (ft_strcmp(lst->content, lst->next->content) > 0)
		{
			swap = lst->content;
			lst->content = lst->next->content;
			lst->next->content = swap;
			lst = tmp;
		}
		else
			lst = lst->next;
	}
	lst = tmp;
	return (lst);
}
void	ft_export(t_list *p, t_data **data, t_info *info)
{
	iniiiit(info);
	if (p->commandes[1] == NULL)
	{
		(sort_list(*data), printenvwithx(data));
		// g_globe.exit_status = 0;
	}
	else
		export_4(data, p, info);
}
