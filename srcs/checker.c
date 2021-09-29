/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychennaf <ychennaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 15:05:44 by ychennaf          #+#    #+#             */
/*   Updated: 2021/06/02 19:51:00 by ychennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_stack_b(t_stack *stack)
{
	stack->node = NULL;
	stack->chunk_size = NULL;
	stack->chunk = NULL;
	stack->size = 0;
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;
	char	*line;
	int		ret;

	if (argc == 1)
		return (0);
	init_stack(&stack_a, check_errors(argv));
	init_stack_b(&stack_b);
	ret = get_next_line(0, &line);
	while (ret > 0)
	{
		check_ins(line, &stack_a, &stack_b);
		free(line);
		ret = get_next_line(0, &line);
	}
	free(line);
	if (!check_sorted(&stack_a) && !stack_b.size)
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	free_stacks(stack_a.node, stack_b.node);
	return (0);
}
