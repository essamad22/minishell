/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhtab <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 18:44:39 by aakhtab           #+#    #+#             */
/*   Updated: 2022/11/12 17:16:02 by aakhtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	char	*str;

	str = (char *)s;
	if (!s)
		return (NULL);
	if (start > ft_strlen(str))
	{
		sub = malloc(1);
		if (!sub)
			return (NULL);
		*sub = '\0';
		return (sub);
	}
	if (len > ft_strlen(str + start))
		len = ft_strlen(str + start);
	sub = malloc(len + 1);
	if (!sub)
		return (NULL);
	ft_memcpy(sub, (str + start), len);
	sub[len] = '\0';
	return (sub);
}
