/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadoue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:49:21 by aadoue            #+#    #+#             */
/*   Updated: 2022/11/09 18:50:49 by aadoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_itoa(int n)
{
	char	*str_nbr;
	long	l_n;
	size_t	n_digits;

	l_n = (long) n;
	if (n < 0)
		l_n *= -1;
	n_digits = ft_nbrlen(l_n, 10) + (n < 0);
	str_nbr = (char *) malloc(n_digits + 1);
	if (! str_nbr)
		return (NULL);
	str_nbr[n_digits--] = '\0';
	while (l_n != 0)
	{
		str_nbr[n_digits--] = l_n % 10 + '0';
		l_n /= 10;
	}
	if (n < 0)
		str_nbr[n_digits] = '-';
	else if (n == 0)
		str_nbr[n_digits] = '0';
	return (str_nbr);
}
