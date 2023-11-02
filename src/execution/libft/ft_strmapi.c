/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhachab <nkhachab@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 23:41:33 by nkhachab          #+#    #+#             */
/*   Updated: 2022/11/06 17:20:46 by nkhachab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char test(unsigned int i, char c)
{
	return(c -= 32);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*output;
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return (NULL);
	output = malloc(ft_strlen((char *)s) + 1);
	if (!output)
		return (NULL);
	while (s[i])
	{
		output[i] = f(i, s[i]);
		i++;
	}
	output[i] = '\0';
	return (output);
}
