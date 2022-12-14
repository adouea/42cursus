/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadoue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 13:21:38 by aadoue            #+#    #+#             */
/*   Updated: 2022/12/14 17:40:05 by aadoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "printf.h"

static void	print()
{
//print while its printable with or without conv
}

int	ft_printf(const char *conv, ...)
{
	int	len_printed;
	va_list ptr;

	va_start(ptr, conv);
	len_printed = 0;
	while (*conv)
	{
		if (*conv == "%")
		{
			conv++;	
			if (*conv == "c") one char
			{
				ft_putchar(va_arg(ptr, int));
    			len_printed++;
			}
			if (*conv == "s") string
			{
				len_printed = len_printed + ft_strlen(conv);
				ft_putstr(va_arg(ptr, const char*));
			}	
    		if (*conv == "p") void * arg in hexa
			if (*conv == "d") nb decimal base 10
    		if (*conv == "i") int base 10
    		if (*conv == "u") unsigned nb decimal base 10
    		if (*conv == "x") nb in hexa in min
    		if (*conv == "X") nb in hexa in MAJ
    		if (*conv == "%") just a %
			{				
				ft_putchar('%');
				len_printed++;
			}
		}
		else
			ft_putstr(*conv)
		conv++;
	}
	va_end(ptr);
	return (len_printed);
}

int	main ()
{
	ft_printf("Hello")
	printf("%i\n", printf("%i\n", -5));
	return (0);
}

https://www.gnu.org/software/libc/manual/html_node/Why-Variadic.html
https://github.com/paulo-santana/ft_printf_tester
https://github.com/Tripouille/printfTester

type va_arg (va_list ptr, type) return the value of the next arg and modify ptr to be on the next arg
