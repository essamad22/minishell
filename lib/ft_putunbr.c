/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhtab <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 18:19:20 by aakhtab           #+#    #+#             */
/*   Updated: 2023/04/25 18:24:28 by aakhtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	nb_print(unsigned int nb)
{
	if (nb > 9)
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

int	ft_putunbr(unsigned int nb)
{
	unsigned int	i;
	int				len;

	i = nb;
	len = 0;
	if (nb == 0)
	{
		nb_print(0);
		return (1);
	}
	while (i)
	{
		i /= 10;
		len++;
	}
	nb_print(nb);
	return (len);
}
