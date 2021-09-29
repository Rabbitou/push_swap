/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychennaf <ychennaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 12:48:04 by ychennaf          #+#    #+#             */
/*   Updated: 2021/05/31 18:48:51 by ychennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!*needle)
		return ((char *)haystack);
	if ((!haystack || !needle) && len == 0)
		return (NULL);
	str = (char *)haystack;
	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i + j] == needle[j] && needle[j] != '\0' && (i + j) < len)
			j++;
		if (needle[j] == '\0')
			return (str + i);
		i++;
	}
	return (0);
}
