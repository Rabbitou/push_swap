/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychennaf <ychennaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 12:34:48 by ychennaf          #+#    #+#             */
/*   Updated: 2021/06/03 13:55:14 by ychennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_countdigit(long int i)
{
	int	count;

	count = 0;
	if (i == 0)
		return (1);
	if (i < 0)
		count++;
	while (i > 0 || i < 0)
	{
		i /= 10;
		count++;
	}
	return (count);
}

void	init_stack(t_stack *stack, char **ret)
{
	int	data;
	int	k;
	int	i;

	stack->type_swap = NONE;
	stack->node = NULL;
	stack->chunk = NULL;
	stack->chunk_size = NULL;
	stack->pivot = NULL;
	i = len_table(ret);
	stack->size = 0;
	while (--i >= 0)
	{
		data = ft_atoi(ret[i]);
		push(stack, data);
		k = 0;
		while (k < i)
		{
			if (ft_atoi(ret[k]) == data)
				raise_error(stack->node, ret, NULL);
			k++;
		}
	}
	free_table(ret);
}

void	free_stacks(t_list *stack_a, t_list *stack_b)
{
	ft_lstclear(&stack_a, free);
	ft_lstclear(&stack_b, free);
}
