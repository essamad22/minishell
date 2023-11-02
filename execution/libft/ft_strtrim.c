/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhachab <nkhachab@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 23:41:43 by nkhachab          #+#    #+#             */
/*   Updated: 2022/11/01 01:31:59 by nkhachab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && (ft_strchr(set, *s1)))
		s1++;
	len = ft_strlen((char *)s1);
	while (len > 0 && (ft_strrchr(set, s1[len])))
		len--;
	return (ft_substr(s1, 0, len + 1));
}
