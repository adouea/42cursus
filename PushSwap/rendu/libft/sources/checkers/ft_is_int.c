/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadoue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 16:08:17 by aadoue            #+#    #+#             */
/*   Updated: 2023/04/09 16:08:33 by aadoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_int(char *number)
{
	if (ft_is_long(number))
	{
		if (! (ft_atoi(number) - ft_atol(number)))
			return (1);
	}
	return (0);
}
