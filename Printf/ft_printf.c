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

static void	print_integer(int n)
{
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
		print_integer(n / 10);
	ft_putchar('0' + n % 10);
}

static void	print_unsigned_integer(unsigned int n)
{
	if (n >= 10)
		print_unsigned_integer(n / 10);
	ft_putchar('0' + n % 10);
}

static void	print_hexadecimal(unsigned int n, char maj)
{
	if (n >= 16)
		print_hexadecimal(n / 16);
	if (n % 16 < 10)
		ft_putchar('0' + n % 16);
	else
		if (maj == 'X')
			ft_putchar('A' + n % 16 - 10);
		if (maj == 'x')
			ft_putchar('a' + n % 16 - 10);
}		

int	ft_printf(const char *conv, ...)
{
	int	len_printed;
	va_list ptr;
	char	conversion;

	va_start(ptr, conv);
	len_printed = 0;
	while (*conv)
	{
		if (*conv == "%")
		{
			conversion = *(++conv); //?rm conversion and direct use of *conv ?
			if (conversion == 'c') //one char
			{
				ft_putchar(va_arg(ptr, int));
    				len_printed++;
			}
			else if (conversion == 's') //string
			{
				len_printed = len_printed + ft_strlen(conv);
				ft_putstr(va_arg(ptr, const char*));
			}	
    			else if (conversion == 'p') //void * arg in hexa
			{
				void *p = va_arg(ptr, void*);
				ft_putstr("0x");
				print_hexadecimal((unsigned long) p, 'x');
			}
			else if (conversion == 'd' || conversion == 'i') //nb decimal ou int base 10
				print_integer(va_arg(ptr, int));
    			else if (conversion == 'u') //unsigned nb decimal base 10
				print_unsigned_integer(va_arg(ptr, unsigned int));
			else if (conversion == 'x' || conversion == 'X') //nb in hexa in min/maj
                                print_hexadecimal(va_arg(ptr, unsigned int), conversion);
    			else if (conversion == "%") //just a %
			{				
				ft_putchar('%');
				len_printed++;
			}
			else
			{
				ft_putchar('%');
				ft_putchar(conversion);
				len_printed = len_printed + 2;
			}
		}
		else
			ft_putchar(*conv)
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
