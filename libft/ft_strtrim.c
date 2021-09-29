/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychennaf <ychennaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 13:00:07 by ychennaf          #+#    #+#             */
/*   Updated: 2021/05/31 18:49:05 by ychennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_beginning(char const *s1, char const *set, size_t j)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0' && s1[j] != '\0')
	{
		if (s1[j] == set[i])
		{
			j++;
			i = 0;
		}
		else
			i++;
	}
	return (j);
}

static size_t	ft_end(char const *s1, char const *set, size_t j)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (s1[j - 1] == set[i])
		{
			j--;
			i = 0;
		}
		else
			i++;
	}
	return (j);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	ls1;
	size_t	lset;
	size_t	begin;
	size_t	end;
	char	*tab;

	if (!s1 || !set)
		return (0);
	ls1 = ft_strlen(s1);
	lset = ft_strlen(set);
	begin = ft_beginning(s1, set, 0);
	if (begin == ls1)
		return (ft_strdup(""));
	end = ft_end(s1, set, ls1);
	if (end < begin)
		return (0);
	tab = malloc(sizeof(char) * (end - begin + 1));
	ls1 = 0;
	if (!tab)
		return (0);
	while (s1[begin] != '\0' && begin < end)
		tab[ls1++] = s1[begin++];
	tab[ls1] = '\0';
	return (tab);
}
