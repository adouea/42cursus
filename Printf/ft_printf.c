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

static int	print_integer(int n)
{
	int	i;
	char	*var;

	i = 0;
	var = NULL;
	if (n < 0)
	{
		i += write(1, "-", 1);
		n = -n;
	}
	if (n >= 10)
		print_integer(n / 10);
	var[0] = '0' + n % 10;
	i += write(1, &var, 1);
	return (i);
}

static int	print_unsigned_integer(unsigned int n)
{
	int	i;
	char	*var;

	i = 0;
	var = NULL;
	if (n >= 10)
		print_unsigned_integer(n / 10);
	var[0] = '0' + n % 10;
	i += write(1, &var, 1);
	return (i);
}

static int	print_hexadecimal(unsigned int n, char maj, char p)
{
	int	i;
	char	*var;

	i = 0;
	var = NULL;
	if (p == 'p')
		i += write(1, "0x", 2);
	if (n >= 16)
		print_hexadecimal((n / 16), maj, p);
	if (n % 16 < 10)
	{
		var[0] = '0' + n % 16; 
		i += write(1, &var, 1);
	}
	else
		if (maj == 'X')
		{
			var[0] = 'A' + n % 16 - 10;
			i += write(1, &var, 1);
		}
		if (maj == 'x')
		{
			var[0] = 'a' + n % 16 - 10;
			i += write(1, &var, 1);
		}
	return (i);
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
		if (*conv == '%')
		{
			conversion = *(++conv); //?rm conversion and direct use of *conv ?
			if (conversion == 'c') //one char
				len_printed += write(1, va_arg(ptr, int), 1); //putchar and putstr in write
			else if (conversion == 's') //string
				len_printed += write(1, va_arg(ptr, const char*), ft_strlen(conv));
    			else if (conversion == 'p') //void * arg in hexa
				len_printed += print_hexadecimal((unsigned long) va_arg(ptr, void*), 'x', 'p'); //void *p = va_arg(ptr, void*);
			else if (conversion == 'd' || conversion == 'i') //nb decimal ou int base 10
				len_printed += print_integer(va_arg(ptr, int));
    			else if (conversion == 'u') //unsigned nb decimal base 10
				len_printed += print_unsigned_integer(va_arg(ptr, unsigned int));
			else if (conversion == 'x' || conversion == 'X') //nb in hexa in min/maj
                                len_printed += print_hexadecimal(va_arg(ptr, unsigned int), conversion, 'z');
    			else if (conversion == '%') //just a %
				len_printed += write(1, "%", 1);
			else
				len_printed += write(1, "%", 1);
		}
		else
			len_printed += write(1, &conv, 1);
		conv++;
	}
	va_end(ptr);
	return (len_printed);
}

int	main ()
{
	ft_printf("%Hello");
	//printf("%i\n", printf("%i\n", -5));
	return (0);
}

//https://www.gnu.org/software/libc/manual/html_node/Why-Variadic.html
//https://github.com/paulo-santana/ft_printf_tester
//https://github.com/Tripouille/printfTester

//type va_arg (va_list ptr, type) return the value of the next arg and modify ptr to be on the next arg
