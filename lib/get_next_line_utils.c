/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhtab <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 21:02:27 by aakhtab           #+#    #+#             */
/*   Updated: 2023/04/25 18:41:38 by aakhtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen2(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

void	*ft_memcpy2(void *dst, const void *src, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;
	size_t			i;

	p1 = (unsigned char *)dst;
	p2 = (unsigned char *)src;
	i = 0;
	if (p1 == p2)
		return (dst);
	while (n > 0)
	{
		p1[i] = p2[i];
		n--;
		i++;
	}
	return (dst);
}

char	*ft_strjoin2(char *str1, char *str2)
{
	char	*new_str;
	size_t	i;

	if (!str1 && !str2)
		return (NULL);
	else if (!str1)
	{
		i = ft_strlen2(str2);
		new_str = malloc(i + 1);
		if (!new_str)
			return (NULL);
		ft_memcpy2(new_str, str2, i);
		new_str[i] = '\0';
		return (new_str);
	}
	i = ft_strlen2(str1) + ft_strlen2(str2);
	new_str = malloc(sizeof(char) * (i + 1));
	if (!new_str)
		return (NULL);
	ft_memcpy2(new_str, str1, ft_strlen2(str1));
	ft_memcpy2((new_str + ft_strlen2(str1)), str2, ft_strlen2(str2));
	new_str[i] = '\0';
	free(str1);
	return (new_str);
}

char	*ft_strchr2(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] && s[i] != (unsigned char )c)
		i++;
	if (s[i] == (unsigned char)c)
		return ((char *)s);
	return (NULL);
}

int	get_len(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}
