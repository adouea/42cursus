/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadoue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:40:06 by aadoue            #+#    #+#             */
/*   Updated: 2023/02/28 14:40:27 by aadoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_readed_line(char *start)
{
	int		i;
	char	*line;

	if (!start || !start[0])
		return (NULL);
	i = 0;
	while (start[i] && start[i] != '\n')
		i++;
	if (start[i] == '\n')
		i++;
	line = (char *)malloc(1 + i);
	if (!line)
		return (NULL);
	i = 0;
	while (start[i] && start[i] != '\n')
	{
		line[i] = start[i];
		i++;
	}
	if (start[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_new_start(char *start)
{
	int		i;
	int		j;
	char	*new_start;

	i = 0;
	while (start[i] && start[i] != '\n')
		i++;
	if (start[i] == '\0')
	{
		free(start);
		return (NULL);
	}
	i += (start[i] == '\n');
	new_start = (char *)malloc(1 + ft_strlen(start) - i);
	if (!new_start)
		return (NULL);
	j = 0;
	while (start[i + j])
	{
		new_start[j] = start[i + j];
		j++;
	}
	new_start[j] = '\0';
	free(start);
	return (new_start);
}

char	*get_next_line(int fd)
{
	int			read_return;
	char		*next_line;
	static char	*start[1024] = {NULL};

	if (fd < 0 || fd > 1023 || BUFFER_SIZE <= 0)
		return (NULL);
	read_return = 1;
	next_line = (char *)malloc(BUFFER_SIZE + 1);
	if (!next_line)
		return (NULL);
	while (!(ft_strchr(start[fd], '\n')) && read_return != 0)
	{
		read_return = read(fd, next_line, BUFFER_SIZE);
		if (read_return == -1)
		{
			free(next_line);
			return (NULL);
		}
		next_line[read_return] = '\0';
		start[fd] = ft_joinprep(start[fd], next_line);
	}
	free(next_line);
	next_line = ft_readed_line(start[fd]);
	start[fd] = ft_new_start(start[fd]);
	return (next_line);
}
