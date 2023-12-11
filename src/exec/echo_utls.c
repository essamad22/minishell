/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_utls.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhachab <nkhachab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 03:47:29 by aakhtab           #+#    #+#             */
/*   Updated: 2023/11/12 09:55:21 by nkhachab         ###   ########.fr       */
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
