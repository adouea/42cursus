/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadoue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 17:36:58 by aadoue            #+#    #+#             */
/*   Updated: 2023/04/09 17:37:09 by aadoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*n_to_str(long int stock, long int size)
{
	long int	stock2;
	char		*str;

	str = ft_calloc(sizeof(char), 1 + size);
	if (!str)
		return (NULL);
	if (stock < 0)
	{
		str[0] = '-';
		stock = stock * -1;
	}
	str[size--] = '\0';
	while (stock != 0)
	{
		stock2 = stock % 10;
		stock = stock / 10;
		str[size] = stock2 + '0';
		size--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char		*str;
	long int	stock;
	long int	size;

	stock = (long int)n;
	size = 0;
	str = NULL;
	if (n == 0)
	{
		str = ft_calloc(sizeof(char), 2);
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	if (n < 0)
		size++;
	while (stock != 0)
	{
		size++;
		stock = stock / 10;
	}
	stock = n;
	str = n_to_str(stock, size);
	return (str);
}
