/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychennaf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 18:19:14 by ychennaf          #+#    #+#             */
/*   Updated: 2019/11/01 13:03:49 by ychennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
