/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhtab <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 07:52:53 by aakhtab           #+#    #+#             */
/*   Updated: 2022/11/12 17:18:42 by aakhtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;
	unsigned int	len;

	if (!s || !f)
		return ;
	len = ft_strlen((char *)s);
	i = 0;
	while (i < len)
	{
		(*f)(i, &s[i]);
		i++;
	}
	s[len] = '\0';
}
