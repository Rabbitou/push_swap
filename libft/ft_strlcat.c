/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychennaf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 16:58:41 by ychennaf          #+#    #+#             */
/*   Updated: 2019/10/30 17:36:43 by ychennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	ldst;
	size_t	lsrc;
	size_t	i;

	i = 0;
	lsrc = ft_strlen(src);
	if (!dst && size == 0)
		return (lsrc);
	ldst = ft_strlen(dst);
	if (size < ldst)
		return (size + lsrc);
	else
	{
		while (i + ldst < size - 1 && src[i] != '\0')
		{
			dst[ldst + i] = src[i];
			i++;
		}
		dst[ldst + i] = '\0';
		return (ldst + lsrc);
	}
}
