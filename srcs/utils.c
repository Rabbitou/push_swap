/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychennaf <ychennaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 18:06:41 by ychennaf          #+#    #+#             */
/*   Updated: 2021/06/03 13:55:07 by ychennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_ins2(char *line, t_stack *stack_a, t_stack *stack_b)
{
	if (!ft_strcmp(line, "ra"))
		rotate(stack_a);
	else if (!ft_strcmp(line, "rb"))
		rotate(stack_b);
	else if (!ft_strcmp(line, "rr"))
	{
		rotate(stack_a);
		rotate(stack_b);
	}
	else if (!ft_strcmp(line, "rra"))
		r_rotate(stack_a);
	else if (!ft_strcmp(line, "rrb"))
		r_rotate(stack_b);
	else if (!ft_strcmp(line, "rrr"))
	{
		r_rotate(stack_a);
		r_rotate(stack_b);
	}
	else
	{
		ft_lstclear(&stack_a->node, free);
		ft_lstclear(&stack_b->node, free);
		raise_error(NULL, NULL, NULL);
	}
}

void	check_ins(char *line, t_stack *stack_a, t_stack *stack_b)
{
	if (!ft_strcmp(line, "sa"))
		swap(stack_a);
	else if (!ft_strcmp(line, "sb"))
		swap(stack_b);
	else if (!ft_strcmp(line, "ss"))
	{
		swap(stack_a);
		swap(stack_b);
	}
	else if (!ft_strcmp(line, "pa"))
	{
		if (stack_b->size)
			push(stack_a, pop(stack_b));
	}
	else if (!ft_strcmp(line, "pb"))
	{
		if (stack_a->size)
			push(stack_b, pop(stack_a));
	}
	else
		check_ins2(line, stack_a, stack_b);
}

static void	exec_ins3(char *line, t_stack *stack_a, t_stack *stack_b)
{
	if (!ft_strcmp(line, "pb"))
	{
		if (stack_a->size)
			push(stack_b, pop(stack_a));
	}
	else if (!ft_strcmp(line, "ra"))
		rotate(stack_a);
	else if (!ft_strcmp(line, "rb"))
		rotate(stack_b);
	else if (!ft_strcmp(line, "rr"))
	{
		rotate(stack_a);
		rotate(stack_b);
	}
	else if (!ft_strcmp(line, "rra"))
		r_rotate(stack_a);
	else if (!ft_strcmp(line, "rrb"))
		r_rotate(stack_b);
	else if (!ft_strcmp(line, "rrr"))
	{
		r_rotate(stack_a);
		r_rotate(stack_b);
	}
	else if (ft_strcmp(line, "end"))
		raise_error(NULL, NULL, NULL);
}

static void	exec_ins2(char *line, t_stack *stack_a, t_stack *stack_b)
{
	if (!ft_strcmp(line, "sb"))
	{
		swap(stack_b);
		if (stack_a->type_swap == SA)
		{
			stack_a->type_swap = NONE;
			ft_putendl_fd("ss", 1);
		}
		else
			stack_a->type_swap = SB;
	}
	else if (!ft_strcmp(line, "ss"))
	{
		swap(stack_a);
		swap(stack_b);
	}
	else if (!ft_strcmp(line, "pa"))
	{
		if (stack_b->size)
			push(stack_a, pop(stack_b));
	}
	else
		exec_ins3(line, stack_a, stack_b);
}

void	exec_ins(char *line, t_stack *stack_a, t_stack *stack_b)
{
	if (!ft_strcmp(line, "sa"))
	{
		swap(stack_a);
		if (stack_a->type_swap == SB)
		{
			stack_a->type_swap = NONE;
			ft_putendl_fd("ss", 1);
		}
		else
			stack_a->type_swap = SA;
	}
	else
		exec_ins2(line, stack_a, stack_b);
	if (ft_strcmp(line, "sa") && ft_strcmp(line, "sb"))
	{
		if (stack_a->type_swap == SA)
			ft_putendl_fd("sa", 1);
		else if (stack_a->type_swap == SB)
			ft_putendl_fd("sb", 1);
		stack_a->type_swap = NONE;
		if (ft_strcmp(line, "end"))
			ft_putendl_fd(line, 1);
	}
}

// void	print_list(t_list *lst, char *line)
// {
// 	t_list	*tmp;

// 	tmp = lst;
// 	ft_putstr_fd("========== ", 1);
// 	ft_putstr_fd(line, 1);
// 	ft_putendl_fd(" ==========", 1);
// 	while (tmp)
// 	{
// 		ft_putnbr_fd(*(int *)tmp->content, 1);
// 		ft_putendl_fd("", 1);
// 		tmp = tmp->next;
// 	}
// }
