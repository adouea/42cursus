/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadoue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 17:27:07 by aadoue            #+#    #+#             */
/*   Updated: 2023/04/09 18:05:37 by aadoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

int	ft_atoi_base(const char *str, int str_base)
{
	int	result;
	int	digit;

	result = 0;
	digit = 0;
	while (*str != '\0')
	{
		digit = *str - '0';
		if (digit < 0 || digit >= str_base)
			break ;
		result = result * str_base + digit;
		str++;
	}
	return (result);
}

/*
int main() {
    char *hex_string = "1A";
    int result = atoi_base(hex_string, 16);
    printf("%d\n", result);
    return 0;
}
*/
