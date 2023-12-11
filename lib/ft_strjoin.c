/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhtab <aakhtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 18:41:43 by aakhtab           #+#    #+#             */
/*   Updated: 2023/11/13 03:53:44 by aakhtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str1;
	char	*str2;
	char	*new_str;
	size_t	i;

	str1 = (char *)s1;
	str2 = (char *)s2;
	if (!str1 || !str2)
		return (NULL);
	i = ft_strlen(str1) + ft_strlen(str2);
	new_str = malloc(sizeof(char) * (i + 1));
	if (!new_str)
		return (NULL);
	ft_memcpy(new_str, str1, ft_strlen(str1));
	ft_memcpy((new_str + ft_strlen(str1)), str2, ft_strlen(str2));
	new_str[i] = '\0';
	return (new_str);
}

char	*ft_strjoin_f(char const *s1, char const *s2)
{
	char	*str1;
	char	*str2;
	char	*new_str;
	size_t	i;

	str1 = (char *)s1;
	str2 = (char *)s2;
	if (!str1 || !str2)
		return (NULL);
	i = ft_strlen(str1) + ft_strlen(str2);
	new_str = malloc(sizeof(char) * (i + 1));
	if (!new_str)
		return (NULL);
	ft_memcpy(new_str, str1, ft_strlen(str1));
	ft_memcpy((new_str + ft_strlen(str1)), str2, ft_strlen(str2));
	new_str[i] = '\0';
	free((char *)s1);
	return (new_str);
}
