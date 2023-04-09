/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadoue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 17:42:03 by aadoue            #+#    #+#             */
/*   Updated: 2023/04/09 17:42:14 by aadoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float	ft_pow(int base, int exp)
{
	float	pow;

	pow = 1;
	if (exp > 0)
	{
		while (exp--)
			pow *= base;
	}
	else
		pow = (float) 1 / ft_pow(base, exp * -1);
	return (pow);
}
