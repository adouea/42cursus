/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadoue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 16:09:21 by aadoue            #+#    #+#             */
/*   Updated: 2023/04/09 16:09:24 by aadoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_decimal(char *n)
{
	size_t	i;

	i = 0;
	while (n[i])
	{
		if ((n[i] == '.') || (n[i] == ','))
			i++;
		if (! n[i] || ! ft_isdigit(n[i]))
			return (0);
		i++;
	}
	return (i && (i == ft_strlen(n)));
}

int	check_hexa(char *n)
{
	size_t	i;

	i = 0;
	while (n[i])
	{
		if ((n[i] == '.') || (n[i] == ','))
			i++;
		if (! ft_strncmp(n + i, "0x", 2) || ! ft_strncmp(n + i, "0X", 2))
			i += 2;
		if (! n[i] || ! ft_ishexadigit(n[i]))
			return (0);
		i++;
	}
	return (i && (i == ft_strlen(n)));
}

int	ft_is_number(char *n)
{
	int		i;
	char	*hexa;

	if (! n)
		return (0);
	i = 0;
	if (ft_count_occ(n, '.') + ft_count_occ(n, ',') > 1)
		return (0);
	else if (n[i] == '+' || n[i] == '-')
		n++;
	hexa = ft_strnstr(n, "0x", ft_strlen(n));
	if (hexa && ft_strnstr(hexa + 1, "0x", ft_strlen(hexa)))
		return (0);
	else if (hexa)
		return (check_hexa(n));
	else
		return (check_decimal(n));
}
