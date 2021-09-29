/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychennaf <ychennaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 19:45:56 by ychennaf          #+#    #+#             */
/*   Updated: 2021/05/31 18:41:34 by ychennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	init_var(int n, long int *i, int *br)
{
	*i = n;
	*br = 0;
}

static int	ft_countdigit(long int i)
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

char	*ft_itoa(int n)
{
	char		*tab;
	long int	i;
	int			count;
	int			br;

	init_var(n, &i, &br);
	count = ft_countdigit(i);
	tab = malloc(sizeof(char) * (count + 1));
	if (!tab)
		return (0);
	tab[count--] = '\0';
	if (i == 0)
		tab[0] = '0';
	if (i < 0)
	{
		br++;
		tab[0] = '-';
		i = -i;
	}
	while (count >= br)
	{
		tab[count--] = (i % 10) + '0';
		i /= 10;
	}
	return (tab);
}
