/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint_hexa.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadoue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 12:56:17 by aadoue            #+#    #+#             */
/*   Updated: 2023/01/03 16:31:30 by aadoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_uint_hexa(unsigned long long n, const char *base)
{
	unsigned long long	base_len;
	int					count;

	count = 0;
	base_len = str_len(base);
	if (n >= base_len)
	{
		ft_print_uint_hexa(n / base_len, base);
		ft_print_uint_hexa(n % base_len, base);
	}
	else
		write(1, &base[n], 1);
	count += ft_unumlen(n, base_len);
	return (count);
}
