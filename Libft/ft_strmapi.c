/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadoue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 11:57:41 by aadoue            #+#    #+#             */
/*   Updated: 2022/11/08 14:36:21 by aadoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*stock;

	i = 0;
	if (!s)
		return (NULL);
	stock = ft_calloc(sizeof(char), (ft_strlen(s) + 1));
	if (stock)
	{
		while (s[i] != '\0')
		{
			stock[i] = (*f)(i, s[i]);
			i++;
		}
	}
	return (stock);
}
