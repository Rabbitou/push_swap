/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychennaf <ychennaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 15:42:03 by ychennaf          #+#    #+#             */
/*   Updated: 2021/05/24 10:47:19 by ychennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *stack, int item)
{
	int	*data;

	data = ft_calloc(1, sizeof(int));
	*data = item;
	ft_lstadd_front(&stack->node, ft_lstnew(data));
	stack->size++;
}
