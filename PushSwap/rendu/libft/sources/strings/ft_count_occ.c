/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_occ.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadoue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 17:08:28 by aadoue            #+#    #+#             */
/*   Updated: 2023/04/09 17:08:30 by aadoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_occ(char *str, char to_find)
{
	int	count;

	count = 0;
	str = ft_strchr(str, to_find);
	while (str++)
	{
		count++;
		str = ft_strchr(str, to_find);
	}
	return (count);
}
