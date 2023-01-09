/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa_u.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadoue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 14:13:55 by aadoue            #+#    #+#             */
/*   Updated: 2023/01/03 16:23:19 by aadoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hexa_u(unsigned long long n, char format)
{
	char	*base;
	int		count;

	count = 0;
	if (format == 'p')
	{
		write(1, "0x", 2);
		count += 2;
	}
	if (format == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (n >= 16)
	{
		ft_print_uint_hexa(n / 16, base);
		ft_print_uint_hexa(n % 16, base);
	}
	else
		write(1, &base[n], 1);
	count += ft_unumlen(n, 16);
	return (count);
}
