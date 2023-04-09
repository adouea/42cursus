/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadoue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:35:50 by aadoue            #+#    #+#             */
/*   Updated: 2023/02/07 15:37:53 by aadoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*f_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	if (c < 0 || c > 127)
		c = c % 256;
	while (s[i] != c && s[i])
		i++;
	if (s[i] == c)
		return (&s[i]);
	return (NULL);
}

int	f_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_joinprep(char *s1, char *s2)
{
	char	*stock;

	if (!s1)
	{
		s1 = (char *)malloc(1);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	stock = (char *)malloc(1 + f_strlen(s1) + f_strlen(s2));
	if (!stock)
		return (NULL);
	stock = ft_joinning(stock, s1, s2);
	free(s1);
	return (stock);
}

char	*ft_joinning(char *stock, char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	while (s1[i])
	{
		stock[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		stock[i + j] = s2[j];
		j++;
	}
	stock[i + j] = '\0';
	return (stock);
}
