/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhachab <nkhachab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 03:48:02 by aakhtab           #+#    #+#             */
/*   Updated: 2023/11/12 09:55:49 by nkhachab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static char	*ft_strcat(char *dest, char *src)
{
	unsigned int	i;

	i = 0;
	while (*(dest + i))
		i++;
	while (*src)
	{
		*(dest + i) = *src;
		src++;
		i++;
	}
	*(dest + i) = '\0';
	return (dest);
}

char	*ft_strjoin01(char *s1, char *s2)
{
	char		*str;
	size_t		s1_len;
	size_t		s2_len;

	if (!s1 || !s2)
		return (0);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str = (char *) malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!str)
		return (0);
	*str = '\0';
	ft_strcat((char *)str, (char *)s1);
	ft_strcat((char *)str, (char *)s2);
	free(s2);
	free(s1);
	return (str);
}

char	*ft_strjoin1(char *s1, char *s2)
{
	char		*str;
	size_t		s1_len;
	size_t		s2_len;

	if (!s1 || !s2)
		return (0);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str = (char *) malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!str)
		return (0);
	*str = '\0';
	ft_strcat((char *)str, (char *)s1);
	ft_strcat((char *)str, (char *)s2);
	return (str);
}

int	check_cmd(char *cmd)
{
	int	i;

	i = -1;
	while (cmd[++i])
	{
		if (!ft_isalnum(cmd[i]))
			return (0);
	}
	return (1);
}

void	print_export(char *s, int fd)
{
	int	i;
	int	l;

	i = 0;
	l = 0;
	while (s[i] && (i == 0 || s[i - 1] != '='))
	{
		if (s[i] == '\0')
			break ;
		ft_putchar_fd(s[i++], fd);
	}
	l = i - 1;
	if (s[l] == '=')
	{
		ft_putchar_fd('\"', fd);
		while (s[i])
			ft_putchar_fd(s[i++], fd);
		ft_putchar_fd('\"', fd);
	}
}
