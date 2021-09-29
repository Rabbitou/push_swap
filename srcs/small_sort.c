/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychennaf <ychennaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 14:11:56 by ychennaf          #+#    #+#             */
/*   Updated: 2021/06/02 15:16:47 by ychennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_top_bottom(t_stack *stack_a)
{
	t_list	*lst;
	int		top;
	int		bottom;

	lst = stack_a->node;
	top = *(int *)lst->content;
	lst = lst->next;
	while (lst->next)
	{
		lst = lst->next;
	}
	bottom = *(int *)lst->content;
	if (top > bottom)
		return (1);
	else
		return (0);
}

int	get_smallest(t_stack *stack_a)
{
	int	smallest;
	int	*tab;	

	smallest = 0;
	tab = list_to_tab(stack_a->node);
	quicksort(tab, 0, stack_a->size - 1);
	smallest = tab[0];
	free(tab);
	return (smallest);
}

void	small_sort(t_stack *a, t_stack *b)
{
	int	smallest;

	while (1)
	{
		if (a->node)
			smallest = get_smallest(a);
		if (!check_sorted(a) && !b->size)
			break ;
		else if (!check_sorted(a) && b->size)
			exec_ins("pa", a, b);
		else if (*(int *)a->node->content == smallest)
			exec_ins("pb", a, b);
		else if (check_top_bottom(a))
			exec_ins("ra", a, b);
		else if (*(int *)a->node->content > *(int *)a->node->next->content)
			exec_ins("sa", a, b);
		else
			exec_ins("ra", a, b);
	}
	exec_ins("end", a, b);
}
