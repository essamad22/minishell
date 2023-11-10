/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_utls.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhtab <aakhtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 03:47:29 by aakhtab           #+#    #+#             */
/*   Updated: 2023/11/10 03:47:30 by aakhtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/minishell.h"

void	print_n_echo(char **cmd, int fd, int i)
{
	while (cmd[i])
	{
		ft_putstr_fd(cmd[i++], fd);
		if (cmd[i])
			ft_putchar_fd(' ', fd);
	}
}
