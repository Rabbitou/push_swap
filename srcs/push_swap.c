/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychennaf <ychennaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 18:22:37 by ychennaf          #+#    #+#             */
/*   Updated: 2021/06/02 15:01:39 by ychennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	new_pivot_if_no_less(t_stack *stack_a, t_stack *stack_b, int *push_count)
{
	int	*push_c;

	if (check_less_pivot(stack_a->chunk, *stack_a->pivot))
	{
		if (*push_count != 0)
		{
			push_c = malloc(sizeof(int));
			*push_c = *push_count;
			ft_lstadd_front(&stack_b->chunk_size, ft_lstnew(push_c));
		}
		*push_count = 0;
		free(stack_a->pivot);
		stack_a->pivot = get_pivot(stack_a->chunk);
		return (1);
	}
	return (0);
}

void	handle_new_chunk_in_a(t_stack *a, t_stack *b, int *s_chunk_a)
{
	int	times_rot;
	int	push_count;

	times_rot = 0;
	push_greater_pivot_to_a(a, b, times_rot, s_chunk_a);
	if (*(int *)b->chunk_size->content == 0)
		deletefirstnode(&b->chunk_size);
	ft_lstclear(&b->chunk, free);
	get_chunk_a(a, *s_chunk_a);
	push_count = 0;
	if (a->pivot)
		free(a->pivot);
	a->pivot = get_pivot(a->chunk);
	while (1)
	{
		get_chunk_a(a, *s_chunk_a);
		if (handle_upper_chunk_a(a, b, s_chunk_a, &push_count))
			break ;
		else if (new_pivot_if_no_less(a, b, &push_count))
			;
		else
			push_less_pivot_to_b(a, b, &push_count, s_chunk_a);
	}
}

int	sort_stack2(t_stack *stack_a, t_stack *stack_b, int size_b, int s_chunk_a)
{
	int	i;

	get_chunk(stack_b, *(int *)stack_b->chunk_size->content);
	if (!is_desc(stack_b->node) && !check_sorted(stack_a))
	{
		size_b = stack_b->size;
		i = -1;
		while (++i < size_b)
			exec_ins("pa", stack_a, stack_b);
		return (1);
	}
	else if (handle_upper_chunk_b(stack_a, stack_b))
		;
	else if (!check_greater_pivot(stack_b->chunk, *stack_b->pivot)
		&& !check_sorted(stack_a))
		handle_new_chunk_in_a(stack_a, stack_b, &s_chunk_a);
	return (0);
}

void	sort_stack(t_stack *stack_a, t_stack *stack_b)
{
	int	chunk_a_size;
	int	size_b;

	stack_a->pivot = get_pivot(stack_a->node);
	while (1)
		if (push_a_to_b(stack_a, stack_b) == 1)
			break ;
	ft_lstadd_front(&stack_b->chunk_size,
		ft_lstnew(alloc_size(stack_b->size - total_chunks(stack_b))));
	chunk_a_size = 0;
	size_b = 0;
	get_chunk(stack_b, *(int *)stack_b->chunk_size->content);
	stack_b->pivot = get_pivot(stack_b->chunk);
	while (stack_b->size)
	{
		if (sort_stack2(stack_a, stack_b, size_b, chunk_a_size))
			break ;
	}
	free(stack_a->pivot);
	free(stack_b->pivot);
	exec_ins("end", stack_a, stack_b);
	ft_lstclear(&stack_a->chunk, free);
	ft_lstclear(&stack_b->chunk, free);
	ft_lstclear(&stack_b->chunk_size, free);
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;

	if (argc == 1)
		return (0);
	stack_b.node = NULL;
	stack_b.chunk_size = NULL;
	stack_b.chunk = NULL;
	stack_b.size = 0;
	init_stack(&stack_a, check_errors(argv));
	if (!check_sorted(&stack_a))
		;
	else if (stack_a.size >= 100)
		sort_stack(&stack_a, &stack_b);
	else
		small_sort(&stack_a, &stack_b);
	free_stacks(stack_a.node, stack_b.node);
	return (0);
}
