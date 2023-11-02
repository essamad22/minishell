/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhtab <aakhtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 21:39:52 by aakhtab           #+#    #+#             */
/*   Updated: 2023/05/21 02:13:48 by aakhtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(int))
{	
	t_list	*ptr;

	if (!lst || !f)
		return ;
	if (lst)
	{
		ptr = lst;
		while (ptr)
		{
			f(ptr->content);
			ptr = ptr->next;
		}
	}
}
