/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhtab <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 00:50:46 by aakhtab           #+#    #+#             */
/*   Updated: 2023/04/25 18:04:35 by aakhtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	hexprint(char nb, int *i)
{
	write(1, &nb, 1);
	*i += 1;
}

void	ft_puthex(unsigned long nb, int *i, char format)
{
	char	*base;

	base = "0123456789abcdef";
	if (format == 'X')
		base = "0123456789ABCDEF";
	if (nb >= 16)
	{
		ft_puthex(nb / 16, i, format);
	}
	hexprint(base[nb % 16], i);
}
