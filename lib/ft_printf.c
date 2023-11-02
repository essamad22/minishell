/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhtab <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 05:05:46 by aakhtab           #+#    #+#             */
/*   Updated: 2023/04/25 18:02:04 by aakhtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	arg_check(char *s, va_list args, int i)
{
	int	len;

	len = 0;
	if (s[i] == '%')
		len += write(1, &s[i], 1);
	else if (s[i] == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (s[i] == 's')
		len += ft_putstr(va_arg(args, char *));
	else if (s[i] == 'd' || s[i] == 'i')
		len += ft_putnbr(va_arg(args, int));
	else if (s[i] == 'u')
		len += ft_putunbr(va_arg(args, unsigned int));
	else if (s[i] == 'x')
		ft_puthex(va_arg(args, unsigned int), &len, 'x');
	else if (s[i] == 'X')
		ft_puthex(va_arg(args, unsigned int), &len, 'X');
	else if (s[i] == 'p')
		len += ft_putadd(va_arg(args, unsigned long));
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		len;
	char	*str;

	i = 0;
	str = (char *)format;
	len = 0;
	va_start(args, format);
	while (str[i])
	{
		if (str[i] != '%')
		{
			write(1, &str[i], 1);
			len++;
		}
		else if (str[i] == '%')
			len += arg_check(str, args, ++i);
		i++;
	}
	va_end(args);
	return (len);
}
