/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlens.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadoue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 14:47:12 by aadoue            #+#    #+#             */
/*   Updated: 2022/12/31 14:55:03 by aadoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	numlen(long long n, int base)
{
	int	i;

	i = 1;
	while (n >= ((long long) base))
	{
		n /= base;
		i++;
	}
	return (i);
}

int	unumlen(unsigned long long n, int base)
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
