/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_head.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadoue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 13:19:17 by aadoue            #+#    #+#             */
/*   Updated: 2023/01/03 13:35:05 by aadoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <unistd.h>

int	ft_print_hexa_min(unsigned long long n);

int	ft_print_head(unsigned long long p)
{
	int	count;

	count = 0;
	if (p == 0)
	{
		count += write(1, "(nil)", 5);
		return (count);
	}
	count += write(1, "0x", 2);
	count += ft_print_hexa_min(p);
	return (count);
}
