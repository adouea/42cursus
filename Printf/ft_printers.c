/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadoue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 13:37:33 by aadoue            #+#    #+#             */
/*   Updated: 2022/12/31 15:16:22 by aadoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int  print_char(char c)
{
	int	count;

	count = 1;
	write(1, &c, 1);
	return (count);
}

int  print_str(char *s)
{
	int i;
	int	count;

	i = 0;
	count = 0;
	if (!s)
	{   
		count += write(1, "(null)", 6);
		return (count);
	}
	while (s[i])
	{   
		count += print_char(s[i]);
		i++;
	}
	return (count);
}

int  print_int(long long n)
{
	int		count;

	count = 0;
	if (n < 0)
	{   
		count += print_char('-');
		n = -n;
	}
	if (n >= 10)
		print_int(n / 10);
	print_char('0' + n % 10);
	count += numlen(n, 10);
	return (count);
}

int  print_uint(unsigned long long n)
{
	int	count;

	count = 0;
	if (n >= 10)
		print_uint(n / 10);
	print_char('0' + n % 10);
	count += unumlen(n, 10);
	return (count);
}  
