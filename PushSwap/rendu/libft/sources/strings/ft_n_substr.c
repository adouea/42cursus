/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_n_substr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadoue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 17:10:22 by aadoue            #+#    #+#             */
/*   Updated: 2023/04/09 17:10:23 by aadoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_n_substr(char const *str, char char_split)
{
	size_t	cnt;
	size_t	reset;

	cnt = 0;
	reset = 1;
	while (str && *str)
	{
		if (*str != char_split && reset)
		{
			cnt++;
			reset = 0;
		}
		else if (*str == char_split)
			reset = 1;
		str++;
	}
	return (cnt);
}
