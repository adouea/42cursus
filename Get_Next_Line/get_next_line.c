/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadoue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:38:55 by aadoue            #+#    #+#             */
/*   Updated: 2023/02/07 14:40:39 by aadoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	static char	*start;

	if (fd < 0 || fd > 1023 || BUFFER_SIZE <= 0)
		return (NULL);
	read_return = 1;
	next_line = (char *)malloc(BUFFER_SIZE + 1);
	if (!next_line)
		return (NULL);
	while (!(ft_strchr(start, '\n')) && read_return != 0)
	{
		read_return = read(fd, next_line, BUFFER_SIZE);
		if (read_return == -1)
		{
			free(next_line);
			return (NULL);
		}
		next_line[read_return] = '\0';
		start = ft_joinprep(start, next_line);
	}
	free(next_line);
	next_line = ft_readed_line(start);
	start = ft_new_start(start);
	return (next_line);
}
