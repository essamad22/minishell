/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhtab <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:08:16 by aakhtab           #+#    #+#             */
/*   Updated: 2022/10/30 16:42:09 by aakhtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check(char a, char set)
{
	if (a == set)
		return (1);
	return (0);
}

static int	end(char *s1, char *s2)
{
	int	i;
	int	j;

	i = ft_strlen(s1) - 1;
	j = 0;
	while (s2[j] != '\0' && i > 0)
	{
		while (check(s1[i], s2[j]) && i > 0)
		{
			i--;
			j = 0;
		}
		j++;
	}
	return (i);
}

static unsigned int	start(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s2[j] != '\0')
	{
		while (check(s1[i], s2[j]))
		{
			i++;
			j = 0;
		}
		j++;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*str;
	char			*new_s;
	size_t			len;
	unsigned int	_start;

	str = (char *)s1;
	if (!s1 || !set)
		return (NULL);
	_start = start(str, (char *)set);
	len = end(str + _start, (char *)set);
	new_s = ft_substr(s1, _start, len + 1);
	return (new_s);
}
