/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhachab <nkhachab@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 23:40:48 by nkhachab          #+#    #+#             */
/*   Updated: 2022/11/06 15:00:53 by nkhachab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*p_dest;
	char	*p_src;

	i = 0;
	p_dest = (char *)dst;
	p_src = (char *)src;
	if (!dst && !src)
		return (0);
	if (dst == src)
		return (dst);
	if (p_dest > p_src)
		while (len--)
			(p_dest[len] = p_src[len]);
	else
	{
		while (i < len)
		{
			(p_dest[i] = p_src[i]);
			i++;
		}
	}
	return (dst);
}
