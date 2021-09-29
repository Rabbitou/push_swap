/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychennaf <ychennaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 12:10:08 by ychennaf          #+#    #+#             */
/*   Updated: 2021/06/02 16:09:22 by ychennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	swap_quick(int *a, int *b)
{
	int	t;

	t = *a;
	*a = *b;
	*b = t;
}

static int	partition (int *arr, int low, int high)
{
	int	pivot;
	int	i;
	int	j;

	pivot = arr[high];
	i = low - 1;
	j = low - 1;
	while (++j <= high - 1)
	{
		if (arr[j] < pivot)
		{
			i++;
			swap_quick(&arr[i], &arr[j]);
		}
	}
	swap_quick(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void	quicksort(int arr[], int low, int high)
{
	int	pi;

	pi = 0;
	if (low < high)
	{
		pi = partition(arr, low, high);
		quicksort(arr, low, pi - 1);
		quicksort(arr, pi + 1, high);
	}
}
