/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadoue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 13:15:56 by aadoue            #+#    #+#             */
/*   Updated: 2023/02/28 14:29:57 by aadoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	char	*stock;
	int		i;

	i = 0;
	while (src[i])
		i++;
	stock = (char *)malloc(i + 1);
	if (!stock)
		return (0);
	i = 0;
	while (src[i])
	{
		stock[i] = src[i];
		i++;
	}
	stock[i] = '\0';
	return (stock);
}
