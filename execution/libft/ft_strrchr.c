/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhachab <nkhachab@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 23:41:41 by nkhachab          #+#    #+#             */
/*   Updated: 2022/11/01 01:30:02 by nkhachab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*t;
	char	t2;
	int		i;

	t = (char *)s;
	t2 = (char)c;
	i = ft_strlen(t);
	while (i != 0)
	{
		if (t[i] == t2)
			return (t + i);
		i--;
	}
	if (t[i] == t2)
		return (t + i);
	return (0);
}
