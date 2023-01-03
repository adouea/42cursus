/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa_maj.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadoue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 13:26:26 by aadoue            #+#    #+#             */
/*   Updated: 2023/01/03 13:38:37 by aadoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_print_char(char c);

int	ft_unumlen(unsigned long long n, int base);

int	ft_print_hexa_maj(unsigned long long n)
{
	int	count;

	count = 0;
	while (n > 4294967295)
		n = n % 4294967296;
	if (n >= 16)
		ft_print_hexa_maj(n / 16);
	if (n % 16 < 10)
		ft_print_char('0' + n % 16);
	else
		ft_print_char('A' + n % 16 - 10);
	count += ft_unumlen(n, 16);
	return (count);
}
