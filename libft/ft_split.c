/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychennaf <ychennaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 18:15:12 by ychennaf          #+#    #+#             */
/*   Updated: 2021/05/31 18:07:10 by ychennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	n_words(char const *str, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] == c)
			i++;
		while (str[i] != c && str[i] != '\0')
			i++;
		if (str[i] == c || str[i] == '\0')
		{
			count++;
			if (str[i] != '\0')
				i++;
		}
	}
	return (count);
}

static char	**ft_free(char **tab, int c_tab)
{
	int	i;

	i = 0;
	while (i <= c_tab)
		free(tab[i++]);
	free(tab);
	return (NULL);
}

static int	init_var(const char *str, char **tab, int *c_tab, int *a)
{
	if (!str || !tab)
		return (1);
	*c_tab = 0;
	*a = 0;
	return (0);
}

static int	first_loop(const char *str, int i, char c)
{
	while (str[i] != '\0' && str[i] != c)
		(i)++;
	return (i);
}

char	**ft_split(char const *str, char c)
{
	char	**tab;
	int		i;
	int		a;
	int		c_tab;

	tab = (char **)malloc(sizeof(char *) * (n_words(str, c) + 1));
	if (init_var(str, tab, &c_tab, &a))
		return (0);
	while (str[a] != '\0')
	{
		i = a;
		i = first_loop(str, i, c);
		if (a < i)
		{
			tab[c_tab] = malloc(sizeof(char) * ((i - a) + 1));
			if (!tab[c_tab])
				return (ft_free(tab, c_tab));
			ft_strlcpy(tab[c_tab++], str + a, i - a + 1);
			a = i;
		}
		if (str[a] != '\0')
			a++;
	}
	tab[c_tab] = 0;
	return (tab);
}
