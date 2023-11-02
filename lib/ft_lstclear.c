/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhtab <aakhtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 13:47:01 by aakhtab           #+#    #+#             */
/*   Updated: 2023/05/21 02:16:55 by aakhtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(int))
{
	t_list	*ptr;
	t_list	*save;

	if (!(*lst) || !del)
		return ;
	ptr = *lst;
	while (ptr)
	{
		save = ptr->next;
		ft_lstdelone(ptr, del);
		ptr = save;
	}
	*lst = NULL;
}
