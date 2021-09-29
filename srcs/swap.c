/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychennaf <ychennaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 15:38:56 by ychennaf          #+#    #+#             */
/*   Updated: 2021/05/24 10:46:04 by ychennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack)
{
	int	swap1;
	int	swap2;

	if (stack->size < 2)
		return ;
	swap1 = pop(stack);
	swap2 = pop(stack);
	push(stack, swap1);
	push(stack, swap2);
}
