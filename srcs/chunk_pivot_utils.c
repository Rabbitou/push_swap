/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_pivot_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychennaf <ychennaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 20:00:04 by ychennaf          #+#    #+#             */
/*   Updated: 2021/05/31 20:29:35 by ychennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_chunk_a(t_stack *stack, int size)
{
	t_list	*tmp;
	int		i;

	i = 0;
	if (stack->chunk)
		ft_lstclear(&stack->chunk, free);
	stack->chunk = NULL;
	if (!size || !stack->node)
		return ;
	tmp = stack->node;
	while (i < size)
	{
		ft_lstadd_back(&stack->chunk,
			ft_lstnew(alloc_size(*(int *)tmp->content)));
		tmp = tmp->next;
		i++;
	}
}

void	get_chunk(t_stack *stack, int size)
{
	t_list	*tmp;
	int		i;

	i = 0;
	if (stack->chunk)
		ft_lstclear(&stack->chunk, free);
	stack->chunk = NULL;
	if (!stack->chunk_size || !stack->node)
		return ;
	tmp = stack->node;
	while (i < size)
	{
		ft_lstadd_back(&stack->chunk,
			ft_lstnew(alloc_size(*(int *)tmp->content)));
		tmp = tmp->next;
		i++;
	}
}

int	*get_pivot(t_list *lst)
{
	int	*ret;
	int	*tab;

	ret = NULL;
	ret = (int *)malloc(sizeof(int));
	tab = list_to_tab(lst);
	quicksort(tab, 0, ft_lstsize(lst) - 1);
	*ret = tab[ft_lstsize(lst) / 2];
	free(tab);
	return (ret);
}

int	check_less_pivot(t_list *lst, int pivot)
{
	t_list	*tmp;

	tmp = lst;
	while (tmp)
	{
		if (*(int *)tmp->content < pivot)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	check_greater_pivot(t_list *lst, int pivot)
{
	t_list	*tmp;

	tmp = lst;
	while (tmp)
	{
		if (*(int *)tmp->content > pivot)
		{
			return (0);
		}
		tmp = tmp->next;
	}
	return (1);
}
