/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychennaf <ychennaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 16:55:36 by ychennaf          #+#    #+#             */
/*   Updated: 2021/05/24 10:46:53 by ychennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pop(t_stack *stack)
{
	int		val;
	t_list	*tmp;

	val = *(int *)stack->node->content;
	tmp = stack->node;
	stack->node = stack->node->next;
	stack->size--;
	free(tmp->content);
	free(tmp);
	return (val);
}
