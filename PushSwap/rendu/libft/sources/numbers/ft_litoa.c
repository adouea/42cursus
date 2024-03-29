/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_litoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadoue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 17:35:54 by aadoue            #+#    #+#             */
/*   Updated: 2023/04/09 17:35:59 by aadoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_litoa(long n)
{
	char	*str_nbr;
	size_t	tmp;
	size_t	n_digits;

	if (n < 0)
		tmp = n * -1;
	else
		tmp = n;
	n_digits = ft_nbrlen(tmp, 10) + (n < 0);
	str_nbr = (char *) malloc(n_digits + 1);
	if (! str_nbr)
		return (NULL);
	str_nbr[n_digits--] = '\0';
	while (tmp != 0)
	{
		str_nbr[n_digits--] = tmp % 10 + '0';
		tmp /= 10;
	}
	if (n < 0)
		str_nbr[n_digits] = '-';
	else if (n == 0)
		str_nbr[n_digits] = '0';
	return (str_nbr);
}
