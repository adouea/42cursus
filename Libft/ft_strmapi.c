/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadoue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 11:57:41 by aadoue            #+#    #+#             */
/*   Updated: 2022/11/05 15:12:44 by aadoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s);

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*stock;

	i = 0;
	stock = malloc((ft_strlen(s) + 1) * sizeof(char));
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
