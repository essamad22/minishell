/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhtab <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:19:50 by aakhtab           #+#    #+#             */
/*   Updated: 2022/10/30 16:33:21 by aakhtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*p1;
	char	*p2;

	p1 = (char *)haystack;
	p2 = (char *)needle;
	i = 0;
	j = 0;
	if (p2[i] == '\0')
		return (p1);
	while (p1[i] != '\0' )
	{
		j = 0;
		while (p1[i + j] == p2[j] && (i + j) < len)
		{
			j++;
			if (p2[j] == '\0')
			{
				return (p1 + i);
			}
		}
		i++;
	}
	return (0);
}
