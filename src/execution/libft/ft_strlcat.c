/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhachab <nkhachab@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 23:41:23 by nkhachab          #+#    #+#             */
/*   Updated: 2022/11/03 22:18:54 by nkhachab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len_dest;
	size_t	len_src;
	size_t	len_dest_src;

	if (!src || !dstsize)
		return (ft_strlen(src));
	len_dest = ft_strlen(dst);
	len_src = ft_strlen((char *)src);
	len_dest_src = len_dest + len_src;
	if (dstsize <= len_dest || dstsize == 0)
		return (len_src + dstsize);
	i = 0;
	dstsize = dstsize - len_dest - 1;
	while (src[i] != '\0' && i < dstsize)
		dst[len_dest++] = src[i++];
	dst[len_dest] = '\0';
	return (len_dest_src);
}
