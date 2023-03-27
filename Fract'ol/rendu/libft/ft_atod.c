/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadoue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 13:30:07 by aadoue            #+#    #+#             */
/*   Updated: 2023/03/08 13:39:30 by aadoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_atod(char *s)
{
	int		zeros;
	char	*dot;
	double	left;
	double	right;

	if (!s)
		return (0.0);
	left = ft_atoi(s);
	dot = ft_strchr(s, '.');
	if (!dot)
		return (left);
	zeros = 0;
	dot++;
	while (*dot++ == '0')
		zeros++;
	dot -= zeros + 1;
	right = ft_atoi(dot);
	while (right >= 1)
		right = right / 10.0;
	while (zeros-- != 0)
		right = right / 10.0;
	if (s[0] == '-' && s[1] == '0')
		return ((left + right) * -1.0);
	return (left + right);
}
