/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadoue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 12:54:13 by aadoue            #+#    #+#             */
/*   Updated: 2023/01/03 13:09:55 by aadoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_print_char(char c);
int	ft_unumlen(unsigned long long n, int base);

int	ft_print_uint(unsigned long long n)
{
	int	count;

	count = 0;
	if (n >= 10)
		ft_print_uint(n / 10);
	ft_print_char('0' + n % 10);
	count += ft_unumlen(n, 10);
	return (count);
}
