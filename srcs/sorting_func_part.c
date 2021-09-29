/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_func_part.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychennaf <ychennaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 20:31:22 by ychennaf          #+#    #+#             */
/*   Updated: 2021/06/01 12:57:00 by ychennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_a_to_b(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size == 2)
	{
		if (check_sorted(stack_a))
			exec_ins("sa", stack_a, stack_b);
		return (1);
	}
	else if (check_less_pivot(stack_a->node, *stack_a->pivot))
	{
		free(stack_a->pivot);
		stack_a->pivot = get_pivot(stack_a->node);
		ft_lstadd_front(&stack_b->chunk_size,
			ft_lstnew(alloc_size(stack_b->size - total_chunks(stack_b))));
	}
	else if (*(int *)stack_a->node->content < *stack_a->pivot)
		exec_ins("pb", stack_a, stack_b);
	else
		check_rot(stack_a, stack_b);
	return (0);
}

void	push_less_pivot_to_b(t_stack *a, t_stack *b, int *p_c, int *s_chunk_a)
{
	int	times_rot;

	times_rot = 0;
	while (*s_chunk_a && !check_less_pivot(a->chunk, *a->pivot))
	{
		get_chunk_a(a, *s_chunk_a);
		if (*(int *)a->chunk->content < *a->pivot)
		{
			exec_ins("pb", a, b);
			(*s_chunk_a)--;
			(*p_c)++;
			deletefirstnode(&a->chunk);
		}
		else if (*(int *)a->chunk->content >= *a->pivot)
		{
			exec_ins("ra", a, b);
			times_rot++;
			(*s_chunk_a)--;
		}
	}
	while (times_rot--)
	{
		exec_ins("rra", a, b);
		(*s_chunk_a)++;
	}
}

void	push_greater_pivot_to_a(t_stack *a, t_stack *b, int rot, int *s_chunk_a)
{
	while (!check_greater_pivot(b->chunk, *b->pivot))
	{
		get_chunk(b, *(int *)b->chunk_size->content);
		if (*(int *)b->chunk_size->content
			&& *(int *)b->chunk->content > *b->pivot)
		{
			exec_ins("pa", a, b);
			(*(int *)b->chunk_size->content)--;
			(*s_chunk_a)++;
			deletefirstnode(&b->chunk);
		}
		else if (*(int *)b->chunk_size->content
			&& *(int *)b->chunk->content <= *b->pivot)
		{
			exec_ins("rb", a, b);
			(*(int *)b->chunk_size->content)--;
			rot++;
		}
	}
	while (rot)
	{
		exec_ins("rrb", a, b);
		(*(int *)b->chunk_size->content)++;
		rot--;
	}
}

int	handle_upper_chunk_b(t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	if (!is_desc(stack_b->chunk) && !check_sorted(stack_a))
	{
		i = -1;
		while (++i < *(int *)stack_b->chunk_size->content)
			exec_ins("pa", stack_a, stack_b);
		*(int *)stack_b->chunk_size->content = 0;
		deletefirstnode(&stack_b->chunk_size);
		return (1);
	}
	else if (*(int *)stack_b->chunk_size->content == 2)
	{
		exec_ins("sb", stack_a, stack_b);
		return (1);
	}
	else if (check_greater_pivot(stack_b->chunk, *stack_b->pivot)
		&& !check_sorted(stack_a))
	{
		free(stack_b->pivot);
		stack_b->pivot = get_pivot(stack_b->chunk);
		return (1);
	}
	else
		return (0);
}

int	handle_upper_chunk_a(t_stack *a, t_stack *b, int *s_chunk_a, int *p_c)
{
	int	*push_c;

	if (a->chunk && *s_chunk_a <= 2)
	{
		if (check_sorted(a))
			exec_ins("sa", a, b);
		if (p_c != 0)
		{
			push_c = malloc(sizeof(int));
			*push_c = *p_c;
			ft_lstadd_front(&b->chunk_size, ft_lstnew(push_c));
		}
		*s_chunk_a = 0;
		*p_c = 0;
		return (1);
	}
	return (0);
}
