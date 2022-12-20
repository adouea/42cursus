/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadoue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 13:21:38 by aadoue            #+#    #+#             */
/*   Updated: 2022/12/20 17:00:34 by aadoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "printf.h"

static int	ft_putchar_return(char c)
{
	int	i;

	i = 0;
	write(1, &c, 1);
	i++;
	return (i);
}

static int	ft_putstr_return(char *s)
{
	int	i;
	int retour;
	
	i = 0;
	retour = 0;
	while (s[i])
	{
		retour += ft_putchar_return(s[i]);
		i++;
	}
	return (retour);
}

static int	print_integer(int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		i += ft_putchar_return('-');
		n = -n;
	}
	if (n >= 10)
		print_integer(n / 10);
	i += ft_putchar_return('0' + n % 10);
	return (i);
}

static int	print_unsigned_integer(unsigned int n)
{
	int	i;

	i = 0;
	if (n >= 10)
		print_unsigned_integer(n / 10);
	i += ft_putchar_return('0' + n % 10);
	return (i);
}

static int	print_hexadecimal(unsigned long n, char maj)
{
	int	i;

	i = 0;
	if (n >= 16)
		print_hexadecimal((n / 16), maj);
	if (n % 16 < 10)
		i += ft_putchar_return('0' + n % 16);
	else
	{
		if (maj == 'X')
			i += ft_putchar_return('A' + n % 16 - 10);
		if (maj == 'x')
			i += ft_putchar_return('a' + n % 16 - 10);
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
			if (conversion == 'c')
				len_printed += ft_putchar_return(va_arg(ptr, int));
			else if (conversion == 's')
				len_printed += ft_putstr_return(va_arg(ptr, char*));
    		else if (conversion == 'p')
				{
					len_printed += write(1, "0x", 2);			
					len_printed += print_hexadecimal((unsigned long) va_arg(ptr, void*), 'x');
				}			
			else if (conversion == 'd' || conversion == 'i')
				len_printed += print_integer(va_arg(ptr, int));
    		else if (conversion == 'u')
				len_printed += print_unsigned_integer(va_arg(ptr, unsigned int));
			else if (conversion == 'x' || conversion == 'X')
				len_printed += print_hexadecimal(va_arg(ptr, unsigned long), conversion);
   			else if (conversion == '%')
				len_printed += write(1, "%", 1);
			else
				len_printed += write(1, "%", 1);
		}
		else
			len_printed += ft_putchar_return(*conv);
		conv++;
	}
	va_end(ptr);
	return (len_printed);
}

int	main ()
{
	//char c[100];
	ft_printf("%X", 10);
	//printf("%i\n", printf("%i\n", -5));
	return (0);
}

gestion des erreurs :
invalid format specifiers = %f ou %l... = print("Error: invalid format specifier\n")
insufficient arguments = ("%d%d", 10)... = print("Error: insufficient arguments\n")
output failure = if return is < 0 so failure to print (stdout closed ?) = print("Error: output failure\n"invalid args = NULL pointer as a string (char *str = NULL, printf("%s", str)) = Print("Error: invalid argument\n") , same using case as previous with the return value

//https://www.gnu.org/software/libc/manual/html_node/Why-Variadic.html
//https://github.com/paulo-santana/ft_printf_tester
//https://github.com/Tripouille/printfTester

//type va_arg (va_list ptr, type) return the value of the next arg and modify ptr to be on the next arg
