/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychennaf <ychennaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 20:27:29 by ychennaf          #+#    #+#             */
/*   Updated: 2021/06/02 13:07:34 by ychennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_desc(t_list *lst)
{
	t_list	*tmp;

	if (!lst)
		return (0);
	tmp = lst;
	while (tmp->next)
	{
		if (*(int *)tmp->content < *(int *)tmp->next->content)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	get_closestless2(int *tab, int size, int pivot, int type)
{
	int	i;

	if (type == 1)
	{
		i = 0;
		while (i < size)
		{
			if (tab[i] < pivot)
				return (i);
			i++;
		}
	}
	else if (type == 2)
	{
		i = size - 1;
		while (i > size / 2)
		{
			if (tab[i] < pivot)
				return (i);
			i--;
		}
		return (i);
	}
	return (0);
}

int	*get_closestless(t_stack *stack, int pivot)
{
	int				*ret;
	int				*tab;
	int				i;
	unsigned int	count;

	i = 0;
	count = 0;
	ret = (int *)malloc(sizeof(int) * 2);
	tab = list_to_tab(stack->node);
	count = get_closestless2(tab, stack->size, pivot, 1);
	i = get_closestless2(tab, stack->size, pivot, 1);
	if (count <= stack->size - i)
	{
		ret[0] = count;
		ret[1] = 0;
	}
	else
	{
		ret[0] = stack->size - i;
		ret[1] = 1;
	}
	free(tab);
	return (ret);
}

int	total_chunks(t_stack *stack)
{
	int		count;
	t_list	*tmp;

	count = 0;
	tmp = stack->chunk_size;
	while (tmp)
	{
		count += *(int *)tmp->content;
		tmp = tmp->next;
	}
	return (count);
}

void	check_rot(t_stack *stack_a, t_stack *stack_b)
{
	int	*check_rot;

	check_rot = get_closestless(stack_a, *stack_a->pivot);
	while (check_rot[0])
	{
		if (check_rot[1] == 0)
			exec_ins("ra", stack_a, stack_b);
		else
			exec_ins("rra", stack_a, stack_b);
		check_rot[0]--;
	}
	free(check_rot);
}
