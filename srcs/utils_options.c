/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychennaf <ychennaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 18:20:54 by ychennaf          #+#    #+#             */
/*   Updated: 2021/05/24 11:12:51 by ychennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_times(char c, int times)
{
	int	i;

	i = -1;
	while (++i <= times)
		ft_putchar_fd(c, 0);
}
