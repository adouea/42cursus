/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_round_to_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadoue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 17:44:56 by aadoue            #+#    #+#             */
/*   Updated: 2023/04/09 17:45:00 by aadoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_round_to_int(double number)
{
	int		sign;
	long	tmp;
	int		last_digit;

	sign = 0;
	if (number < 0)
	{
		number *= -1;
		sign++;
	}
	if (!(number - ft_part_int(number)))
	{
		if (sign)
			number *= -1;
		return ((int) number);
	}
	tmp = ft_part_int(number * 10);
	last_digit = tmp - ((tmp / 10) * 10);
	if (last_digit > 4 && ! sign)
		number += 1;
	else if (last_digit < 5 && sign)
		number -= 1;
	if (sign)
		number *= -1;
	return (ft_part_int(number));
}
