/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_to_tab_alloc_size.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychennaf <ychennaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 20:28:28 by ychennaf          #+#    #+#             */
/*   Updated: 2021/05/31 20:32:32 by ychennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*alloc_size(int size)
{
	int	*i;

	i = malloc(sizeof(int));
	*i = size;
	return (i);
}

int	*list_to_tab(t_list *lst)
{
	t_list	*tmp;
	int		*tab;
	int		i;

	i = 0;
	tab = (int *)malloc(sizeof(int) * ft_lstsize(lst));
	tmp = lst;
	while (tmp)
	{
		tab[i] = *(int *)tmp->content;
		tmp = tmp->next;
		i++;
	}
	return (tab);
}
