/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadoue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 17:28:08 by aadoue            #+#    #+#             */
/*   Updated: 2023/04/09 18:08:29 by aadoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	f_atoi(char *str)
{
	int	n;

	n = 0;
	while (*str != '\0')
	{
		n = n * 10;
		n = n + *str - '0';
		++str;
	}
	return (n);
}

void	ft_print_hex(int n)
{
	char	hex_digits[16] = "0123456789abcdef";
	
	if (n >= 16)
		ft_print_hex(n / 16);
	write(1, &hex_digits[n % 16], 1);
}

/*
int	main(int argc, char **argv)
{
	if (argc == 2)
		ft_print_hex(f_atoi(argv[1]));
	write(1, "\n", 1);
}
*/
