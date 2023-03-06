/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unumlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadoue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 12:43:59 by aadoue            #+#    #+#             */
/*   Updated: 2023/01/03 12:47:10 by aadoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unumlen(unsigned long long n, int base)
{
	int	i;

	i = 1;
	while (n >= (unsigned long long) base)
	{
		n /= base;
		i++;
	}
	return (i);
}
