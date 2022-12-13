/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadoue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 13:21:38 by aadoue            #+#    #+#             */
/*   Updated: 2022/12/12 12:19:38 by aadoue           ###   ########.fr       */
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
	while (*conv)
	{
		if (*conv == "%")
		{
			conv++;	
			if (*conv == "c") one char
				ft_putchar(va_arg(ptr, int));
    			if (*conv == "s") string
    			if (*conv == "p") void * arg in hexa
			if (*conv == "d") nb decimal base 10
    			if (*conv == "i") int base 10
    			if (*conv == "u") unsigned nb decimal base 10
    			if (*conv == "x") nb in hexa in min
    			if (*conv == "X") nb in hexa in MAJ
    			if (*conv == "%") just a %
					ft_putchar('%');
		}
		else
			ft_putstr(*conv)
		conv++;
	}
//len_printed++ at each write if loop, else len for write and len_printed
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
