/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_part_dec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadoue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 17:40:19 by aadoue            #+#    #+#             */
/*   Updated: 2023/04/09 17:40:24 by aadoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float	ft_part_dec(float number)
{
	if (number > 0)
		return (number - ft_part_int(number));
	else
		return (number - ft_part_int(number) - 1);
}
