/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychennaf <ychennaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 19:01:59 by ychennaf          #+#    #+#             */
/*   Updated: 2021/05/24 10:45:46 by ychennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack *stack)
{
	t_stack	tmp;
	int		first;

	if (stack->size <= 1)
		return ;
	first = pop(stack);
	tmp.size = 0;
	while (stack->size)
		push(&tmp, pop(stack));
	push(stack, first);
	while (tmp.size)
		push(stack, pop(&tmp));
}

void	r_rotate(t_stack *stack)
{
	t_stack	tmp;
	int		first;

	if (stack->size <= 1)
		return ;
	tmp.size = 0;
	while (stack->size > 1)
		push(&tmp, pop(stack));
	first = pop(stack);
	while (tmp.size)
		push(stack, pop(&tmp));
	push(stack, first);
}
