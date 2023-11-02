/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhachab <nkhachab@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 23:41:26 by nkhachab          #+#    #+#             */
/*   Updated: 2022/11/01 01:07:19 by nkhachab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	int		len_src;

	i = 0;
	len_src = ft_strlen((char *)src);
	if (!size)
		return (len_src);
	while (src[i] && i < size - 1)
	{
		dst[i] = src [i];
		i++;
	}
	dst[i] = '\0';
	return (len_src);
}
