/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhachab <nkhachab@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 23:41:45 by nkhachab          #+#    #+#             */
/*   Updated: 2022/11/01 01:35:51 by nkhachab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*s1;
	char	*sa;

	s1 = (char *)s;
	i = 0;
	if (!s1)
		return (0);
	if (start >= ft_strlen((char *)s1))
		return (ft_strdup("\0"));
	if (len > ft_strlen(s1) - start)
		len = ft_strlen(s1) - start;
	sa = malloc(sizeof(char) *(len + 1));
	if (!sa)
		return (0);
	while (i < len && s1[i] != '\0')
	{
		sa[i++] = s1[start++];
	}
	sa[i] = '\0';
	return (sa);
}
