/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhtab <aakhtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 03:00:53 by aakhtab           #+#    #+#             */
/*   Updated: 2023/05/24 04:53:19 by aakhtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long ft_atoi(const char *str)
{
	int				sign;
	long	result;
	int				i;

	result = 0;
	sign = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		//if (result > LLONG_MAX && sign == -1)
		//	return (0);
		//if (result > LLONG_MAX && sign == 1)
		//	return (-1);
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result * sign);
}
