#include "execution.h"

int	ft_atoi(const char *str)
{
	unsigned int	num;
	int				i;
	int				np;

	np = 1;
	i = 0;
	num = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\f' || str[i] == '\r'
		|| str[i] == '\n' || str[i] == '\v')
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			np = -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return ((int)(np * num));
}

int	ft_len(long n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n > 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	num;
	int		len;

	num = n;
	len = ft_len(num);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len--] = 0;
	if (num == 0)
	{
		str[0] = '0';
	}
	if (num < 0)
	{
		num *= -1;
		str[0] = '-';
	}
	while (num > 0)
	{
		str[len--] = num % 10 + '0';
		num /= 10;
	}
	return (str);
}


char	*add_to_shlv(char *s)
{
	char	*str;
	int		nb;

	str = bringaftertossawi(s);
	nb = ft_atoi(str);
	free(str);
	nb += 1;
	str = ft_itoa(nb);
	return (str);
}



void	usnet12(char **tmp, char **tmp1, char **str)
{
	*tmp = bringbeforetossawi(*str);
	*tmp1 = add_to_shlv(*str);
	*str = ft_strjoin1(*tmp, *tmp1);
	free(*tmp1);
}


void	ft_list_remove_if(t_data **begin_list, char *data_ref)
{
	t_data	*curr;
	t_data	*prev;

	curr = *begin_list;
	prev = NULL;
	while (curr != NULL)
	{
		if (ft_strncmp(curr->content, data_ref, strlenhtal(curr->content)) == 0
			&& ft_strlen1(data_ref) == strlenhtal(curr->content))
		{
			if (prev == NULL)
				*begin_list = curr->next;
			else
				prev->next = curr->next;
			// (free(curr->content), free(curr));
			(prev == NULL) && (curr = *begin_list);
			(prev != NULL) && (curr = prev->next);
		}
		else
		{
			prev = curr;
			curr = curr->next;
		}
	}
}



int	isalphanum(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (!(ft_isalpha(s[i])) && !(ft_isdigit(s[i])) && s[i] != '_')
			return (1);
		i++;
	}
	return (0);
}

int	ft_unset(t_list *p, t_data **data)
{
	t_data	*tmp;
	int		i;
	int		flag;

	flag = 0;
	i = 1;
	tmp = (*data);
	while (p->commandes[i])
	{
		if (isalphanum(p->commandes[i]))
			(printerr(p->commandes[0], p->commandes[i], "not a valid identifier"),
				flag = 1);
		tmp = (*data);
		while ((tmp))
		{
			if (ft_strncmp(tmp->content, p->commandes[i], ft_strlen(p->commandes[i])) == 0)
			{
				ft_list_remove_if(data, p->commandes[i]);
			}
			tmp = tmp->next;
		}
		i++;
	}
	return (flag);
}
