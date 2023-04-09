/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xatoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadoue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 17:46:39 by aadoue            #+#    #+#             */
/*   Updated: 2023/04/09 17:46:41 by aadoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	find_hexa_char(char c_to_cast)
{
	if (c_to_cast > 'A' && c_to_cast < 'Z')
		return (ft_find_index("0123456789ABCDEF", c_to_cast));
	else
		return (ft_find_index("0123456789abcdef", c_to_cast));
}

int	ft_xatoi(char *str)
{
	int	sign;
	int	nbr;
	int	i;

	nbr = 0;
	sign = 1;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	if (! ft_strncmp(str + i, "0x", 2))
		i += 2;
	while (ft_ishexadigit(str[i]))
		nbr = nbr * 16 + find_hexa_char(str[i++]);
	return (nbr * sign);
}
