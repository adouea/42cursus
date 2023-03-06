/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadoue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:41:48 by aadoue            #+#    #+#             */
/*   Updated: 2023/02/28 14:45:16 by aadoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
	stock = (char *)malloc(1 + ft_strlen(s1) + ft_strlen(s2));
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
