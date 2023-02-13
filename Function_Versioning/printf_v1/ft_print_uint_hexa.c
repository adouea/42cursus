/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint_hexa.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadoue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 12:56:17 by aadoue            #+#    #+#             */
/*   Updated: 2023/01/03 13:11:22 by aadoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <unistd.h>

int	ft_unumlen(unsigned long long n, int base);

int	ft_print_uint_hexa(unsigned long long n, const char *base)
{
	int	count;

	count = 0;
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
