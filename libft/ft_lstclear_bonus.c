/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychennaf <ychennaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 15:56:27 by ychennaf          #+#    #+#             */
/*   Updated: 2021/05/31 18:41:19 by ychennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*list;

	if (!lst || !del)
		return ;
	while (*lst != NULL)
	{
		list = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = list;
	}
}
