/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_index.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadoue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 17:09:08 by aadoue            #+#    #+#             */
/*   Updated: 2023/04/09 17:09:12 by aadoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_find_index(char *str, char value)
{
	int	cnt;

	cnt = -1;
	while (str && *str != value)
	{
		cnt++;
		str++;
	}
	return (cnt);
}
