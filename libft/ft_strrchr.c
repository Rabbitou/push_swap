/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychennaf <ychennaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 11:58:53 by ychennaf          #+#    #+#             */
/*   Updated: 2021/05/31 18:48:56 by ychennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	size_t	len;
	char	*str;

	str = (char *)s;
	len = ft_strlen(str);
	i = len;
	while ((int)i > -1)
	{
		if (str[i] == (char)c)
			return (str + i);
		i--;
	}
	return (0);
}
