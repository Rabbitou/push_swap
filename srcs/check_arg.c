/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychennaf <ychennaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 16:22:22 by ychennaf          #+#    #+#             */
/*   Updated: 2021/06/03 13:54:04 by ychennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stringisnumber(char *str)
{
	int	i;
	int	z;

	z = 0;
	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (ft_strlen(&str[i]) != 1 && str[i] == '0')
	{
		z++;
		i++;
	}
	if (!ft_isdigit(str[i]))
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]) || i - z > 11)
			return (0);
		i++;
	}
	return (1);
}

void	raise_error(t_list *node, char **tab, char **tab2)
{
	t_list	*tmp;

	ft_putendl_fd("Error", 2);
	while (node)
	{
		tmp = node;
		node = node->next;
		free(tmp->content);
		free(tmp);
	}
	if (tab)
		free_table(tab);
	if (tab2)
		free_table(tab2);
	exit(1);
}

static	char	**init_tab2(void)
{
	char	**ret;

	ret = malloc(sizeof(char *));
	ret[0] = NULL;
	return (ret);
}

char	**check_errors(char **argv)
{
	int		i;
	int		j;
	char	**tmp;
	char	**ret;

	ret = init_tab2();
	i = 0;
	while (argv[++i])
	{
		j = -1;
		tmp = ft_split(argv[i], ' ');
		while (tmp[++j])
		{
			if (!ft_stringisnumber(tmp[j]))
				raise_error(NULL, ret, tmp);
			else
			{
				if (ft_atoi(tmp[j]) > INT32_MAX || ft_atoi(tmp[j]) < INT32_MIN)
					raise_error(NULL, ret, tmp);
			}
			ret = tab_join(ret, tmp[j]);
		}
		free_table(tmp);
	}
	return (ret);
}
