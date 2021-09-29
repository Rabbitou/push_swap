/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychennaf <ychennaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 11:22:09 by ychennaf          #+#    #+#             */
/*   Updated: 2021/05/31 18:48:07 by ychennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	int		len;
	char	*str;

	str = (char *)s;
	i = 0;
	len = ft_strlen(str);
	while (i < len + 1)
	{
		if (str[i] == (char)c)
			return (str + i);
		i++;
	}
	return (0);
}
