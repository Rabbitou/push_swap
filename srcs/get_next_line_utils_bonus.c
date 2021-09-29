/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychennaf <ychennaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 16:12:15 by ychennaf          #+#    #+#             */
/*   Updated: 2021/05/24 11:13:57 by ychennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;

	str = (char *)s;
	i = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
			return (str + i + 1);
		i++;
	}
	return (0);
}

char	*cpy_n(char *buf)
{
	int		i;
	char	*retchar;
	int		j;

	i = 0;
	j = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	retchar = malloc(sizeof(char) * (i + 1));
	if (!retchar)
		return (0);
	while (j < i)
	{
		retchar[j] = buf[j];
		j++;
	}
	retchar[j] = '\0';
	return (retchar);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	ls1;
	size_t	ls2;
	char	*tab;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (0);
	ls1 = ft_strlen(s1);
	ls2 = ft_strlen(s2);
	tab = malloc(sizeof(char) * (ls1 + ls2 + 1));
	if (!tab)
		return (0);
	while (s1[i] != '\0')
		tab[j++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		tab[j++] = s2[i++];
	tab[j] = '\0';
	return (tab);
}

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*s2;
	size_t	j;

	j = 0;
	i = ft_strlen(s1);
	s2 = (char *)malloc(sizeof(char) * (i + 1));
	if (!s2)
		return (0);
	while (s1[j] != '\0')
	{
		s2[j] = s1[j];
		j++;
	}
	s2[j] = '\0';
	return (s2);
}
