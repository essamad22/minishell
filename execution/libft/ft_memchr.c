/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhachab <nkhachab@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 23:40:37 by nkhachab          #+#    #+#             */
/*   Updated: 2022/11/03 13:21:30 by nkhachab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*s1;
	char	c1;
	size_t	i;

	i = 0;
	s1 = (char *)s;
	c1 = (char)c;
	while (i < n)
	{
		if (s1[i] == c1)
			return (s1 + i);
		i++;
	}
	return (0);
}
