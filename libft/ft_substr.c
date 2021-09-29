/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychennaf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:17:03 by ychennaf          #+#    #+#             */
/*   Updated: 2019/11/01 13:05:34 by ychennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*tab;
	size_t	lnew;

	i = 0;
	if (!(s))
		return (0);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	lnew = ft_strlen(&s[start]);
	if (lnew >= len)
		lnew = len;
	tab = malloc(sizeof(char) * (lnew + 1));
	if (!tab)
		return (0);
	while (i < lnew && s[start] != '\0')
		tab[i++] = s[start++];
	tab[i] = '\0';
	return (tab);
}
