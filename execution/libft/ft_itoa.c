/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhachab <nkhachab@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 23:40:34 by nkhachab          #+#    #+#             */
/*   Updated: 2022/11/03 12:00:56 by nkhachab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_len(int nbr)
{
	int	count;

	count = 0;
	if (nbr < 0)
		count++;
	while (nbr != 0)
	{
		nbr /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*output;
	int		nbr_count;

	nbr_count = ft_len(n);
	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	output = malloc(sizeof(char) * ft_len(n) + 1);
	if (!output)
		return (NULL);
	if (n < 0)
	{
		output[0] = '-';
		n *= -1;
	}
	output[nbr_count] = '\0';
	nbr_count--;
	while (n != 0)
	{
		output[nbr_count] = n % 10 + '0';
		n /= 10;
		nbr_count--;
	}
	return (output);
}
