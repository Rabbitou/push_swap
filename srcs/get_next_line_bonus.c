/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychennaf <ychennaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 15:09:49 by ychennaf          #+#    #+#             */
/*   Updated: 2021/05/24 11:19:07 by ychennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	join_and_free(char **save, int fd, char *buffer, char **line)
{
	char	*s;
	char	*tmp;

	s = save[fd];
	save[fd] = ft_strjoin(save[fd], buffer);
	free(s);
	tmp = save[fd];
	s = ft_strchr(save[fd], '\n');
	if (s)
	{
		*line = cpy_n(save[fd]);
		save[fd] = ft_strdup(s);
		free(tmp);
		return (1);
	}
	return (0);
}

int	has_errors(int fd, char **save, char **line)
{
	int		ret;

	if (fd < 0 || !line || BUFFER_SIZE <= 0 || fd >= 4864)
		return (-1);
	if (!save[fd])
	{
		save[fd] = malloc(BUFFER_SIZE + 1);
		ret = read(fd, save[fd], 0);
		if (ret == -1)
			return (-1);
		save[fd][ret] = '\0';
	}
	return (1);
}

int	restof(char **line, char **save, int fd)
{
	char	*tmp;
	char	*s;

	tmp = save[fd];
	s = ft_strchr(save[fd], '\n');
	if (s)
	{
		*line = cpy_n(save[fd]);
		save[fd] = ft_strdup(s);
		free(tmp);
		return (1);
	}
	else if (save[fd])
	{
		*line = save[fd];
		save[fd] = NULL;
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char	*save[4864];
	char		*buf;
	int			i;

	if (has_errors(fd, save, line) == -1)
		return (-1);
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (-1);
	i = read(fd, buf, BUFFER_SIZE);
	while (i > 0)
	{
		buf[i] = '\0';
		if (join_and_free(save, fd, buf, line))
		{
			free(buf);
			return (1);
		}
		i = read(fd, buf, BUFFER_SIZE);
	}
	free(buf);
	return (restof(line, save, fd));
}
