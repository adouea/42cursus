/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_unfree.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadoue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 17:13:06 by aadoue            #+#    #+#             */
/*   Updated: 2023/04/09 17:14:10 by aadoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	lines_count(char const *s, char c)
{
	size_t	lines;
	size_t	i;

	lines = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i])
			lines++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (lines);
}

static size_t	ft_jump(char const *s, char c, size_t jump)
{
	if (!ft_strchr(s, c))
		jump = ft_strlen(s);
	else
		jump = ft_strchr(s, c) - s;
	return (jump);
}

char	**ft_split(char const *s, char c)
{	
	size_t	j;
	size_t	jump;
	char	**tab;

	j = 0;
	if (!s)
		return (NULL);
	tab = ft_calloc(sizeof(char *), (lines_count(s, c) + 1));
	if (!tab)
		return (NULL);
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			jump = ft_jump(s, c, jump);
			tab[j] = ft_substr(s, 0, jump);
			j++;
			s += jump;
		}
	}
	return (tab);
}
