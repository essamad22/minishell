/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhtab <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 21:46:23 by aakhtab           #+#    #+#             */
/*   Updated: 2022/10/30 16:35:38 by aakhtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char			*str;
	char			*occ;
	int				len;
	int				i;
	unsigned char	ch;

	ch = (unsigned char)c;
	i = 0;
	occ = NULL;
	str = (char *)s;
	len = ft_strlen(str);
	if (!ch)
		return (str + len);
	while (str[i])
	{
		if (str[i] == ch)
			occ = str + i;
		i++;
	}
	return (occ);
}
