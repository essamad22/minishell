/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhachab <nkhachab@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 23:41:19 by nkhachab          #+#    #+#             */
/*   Updated: 2022/11/04 00:28:46 by nkhachab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*p;
	int		len;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen((char *)s1) + ft_strlen((char *)s2);
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
