/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhachab <nkhachab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 18:42:40 by aakhtab           #+#    #+#             */
/*   Updated: 2023/11/12 04:17:29 by nkhachab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free(char **p)
{
	while (*p)
		free(p++);
	free(p);
}

static int	str_check(char *str, char c)
{
	int	i;
	int	n;

	n = 0;
	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		while (str[i] != '\0' && str[i] == c)
			i++;
		if (str[i] != '\0' && str[i] != c)
			n++;
		while (str[i] != '\0' && str[i] != c)
			i++;
	}
	return (n);
}

static void	str_set(char *str, char **p, char c)
{
	int	i;
	int	n;

	i = 0;
	while (str[i])
	{
		n = 0;
		while (str[i] && str[i] == c)
			i++;
		while (str[i + n] && str[i + n] != c)
			n++;
		if (str[i] && str[i] != c)
		{
			*p = ft_substr(str, i, n);
			if (!p)
				return (ft_free(p));
			p++;
			i += n;
		}
	}
	*p = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**new_str;
	char	*str;
	int		n;

	str = (char *)s;
	if (!s)
		return (NULL);
	n = str_check(str, c);
	new_str = malloc(sizeof(char *) * (n + 1));
	if (new_str == NULL)
		return (NULL);
	str_set(str, new_str, c);
	return (new_str);
}
