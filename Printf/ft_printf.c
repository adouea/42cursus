/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadoue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 13:21:38 by aadoue            #+#    #+#             */
/*   Updated: 2022/12/26 17:27:53 by aadoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdio.h>
#include "ft_printf.h"

static int count = 0;

static int	ft_putchar_return(char c)
{
	count += write(1, &c, 1);
	return (count);
}

static int	ft_putstr_return(char *s)
{
	int	i;
	
	i = 0;
	if (!s)
	{
		count += write(1, "(null)", 6);
		return (count);
	}
	while (s[i])
	{
		ft_putchar_return(s[i]);
		i++;
	}
	return (count);
}

static int	print_integer(int n)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		ft_putchar_return('-');
		nb = -nb;
	}
	if (nb >= 10)
		print_integer(nb / 10);
	ft_putchar_return('0' + nb % 10);
	return (count);
}

static int	print_unsigned_integer(unsigned int n)
{
	if (n >= 10)
		print_unsigned_integer(n / 10);
	ft_putchar_return('0' + n % 10);
	return (count);
}

static int	print_hexadecimal(unsigned long n, char maj, int zero, char p)
{
	if (n == 0 && p == 'p')
	{
		count += write(1, "(nil)", 5);
		return (count);
	}
	if (zero == 0 && n < 16)
		count += write(1, "0x", 2);
	if (n >= 16)
		print_hexadecimal((n / 16), maj, zero, p);
	if (n % 16 < 10)
		ft_putchar_return('0' + n % 16);
	else
	{
		if (maj == 'X')
			ft_putchar_return('A' + n % 16 - 10);
		if (maj == 'x')
			ft_putchar_return('a' + n % 16 - 10);
	}
	return (count);
}		

int	ft_printf(const char *conv, ...)
{
	va_list ptr;
	
	va_start(ptr, conv);
	while (*conv)
	{
		if (*conv == '%')
		{
			conv++;
			if (*conv == 'c')
				ft_putchar_return(va_arg(ptr, int));
			else if (*conv == 's')
				ft_putstr_return(va_arg(ptr, void*));
    		else if (*conv == 'p')
					print_hexadecimal((unsigned long) va_arg(ptr, void*), 'x', 0, *conv);
			else if (*conv == 'd' || *conv == 'i')
				print_integer(va_arg(ptr, int));
    		else if (*conv == 'u')
				print_unsigned_integer(va_arg(ptr, unsigned int));
			else if (*conv == 'x' || *conv == 'X')
				print_hexadecimal(va_arg(ptr, unsigned long), *conv, 1, *conv);
   			else if (*conv == '%')
				count += write(1, "%", 1);
			else
				{
				count += write(1, "%", 1);
				ft_putchar_return(*conv);
				}
		}
		else
			ft_putchar_return(*conv);
		conv++;
	}
	va_end(ptr);
	return (count);
}

int	main ()
{
	//char c[100];
	printf("%i\n", ft_printf(" %x ", 4294967296));
	//printf("\n");
	printf("%i\n", printf(" %x ", 4294967296));
	return (0);
}

//gestion des erreurs :
//invalid format specifiers = %f ou %l... = print("Error: invalid format specifier\n")
//insufficient arguments = ("%d%d", 10)... = print("Error: insufficient arguments\n")
//output failure = if return is < 0 so failure to print (stdout closed ?) = print("Error: output failure\n"invalid args = NULL pointer as a string (char *str = NULL, printf("%s", str)) = Print("Error: invalid argument\n") , same using case as previous with the return value

//https://www.gnu.org/software/libc/manual/html_node/Why-Variadic.html
//https://github.com/paulo-santana/ft_printf_tester
//https://github.com/Tripouille/printfTester

//type va_arg (va_list ptr, type) return the value of the next arg and modify ptr to be on the next arg
