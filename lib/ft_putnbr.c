/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhtab <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 08:59:20 by aakhtab           #+#    #+#             */
/*   Updated: 2023/04/25 18:04:23 by aakhtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	nb_print(long nb)
{
	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
		nb_print(nb);
	}
	else if (nb > 9)
	{
		nb_print(nb / 10);
		nb_print(nb % 10);
	}
	else
	{
		nb += '0';
		write(1, &nb, 1);
	}
}

int	ft_putnbr(long nb)
{
	long	i;
	int		len;

	i = nb;
	len = 0;
	if (nb == 0)
	{
		nb_print(0);
		return (1);
	}
	else if (nb < 0)
	{
		i *= -1;
		len++;
	}
	while (i)
	{
		i /= 10;
		len++;
	}
	nb_print(nb);
	return (len);
}
