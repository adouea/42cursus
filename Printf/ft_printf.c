/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadoue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 13:21:38 by aadoue            #+#    #+#             */
/*   Updated: 2022/12/31 16:48:54 by aadoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <limits.h>
//#include <stdio.h>
#include "ft_printf.h"

static int	print_hexa_min(unsigned long long n, char p)
{
	int	count;

	count = 0;
	if (p != 'p')
	{
		while (n > 4294967295)
			n = n % 4294967296;
	}
	if (n >= 16)
		print_hexa_min(n / 16, p);
	if (n % 16 < 10)
		print_char('0' + n % 16);
	else
		print_char('a' + n % 16 - 10);
	count += unumlen(n, 16);
	return (count);
}

static int	print_hexa_maj(unsigned long long n)
{
	int	count;

	count = 0;
	while (n > 4294967295)
		n = n % 4294967296;
	if (n >= 16)
		print_hexa_maj(n / 16);
	if (n % 16 < 10)
		print_char('0' + n % 16);
	else
		print_char('A' + n % 16 - 10);
	count += unumlen(n, 16);
	return (count);
}

static int  print_0x(unsigned long long p)
{  
	int	count;

	count = 0; 
	if (p == 0)
	{
		count += write(1, "(nil)", 5);
		return (count);
	}
	count += write(1, "0x", 2);
	count += print_hexa_min(p, 'p');
	return (count);
}


static int	prism(va_list lst, const char args, int len_printed)
{
	if (args == 'c')
		len_printed += print_char(va_arg(lst, int));
	else if (args == 's')
		len_printed += print_str(va_arg(lst, char *));
	else if (args == 'p')
		len_printed += print_0x(va_arg(lst, unsigned long long));
	else if (args == 'd' || args == 'i')
		len_printed += print_int(va_arg(lst, int));
	else if (args == 'u')
		len_printed += print_uint(va_arg(lst, unsigned int));
	else if (args == 'x')
		len_printed += print_hexa_min(va_arg(lst, unsigned long long), 'z');
	else if (args == 'X')
		len_printed += print_hexa_maj(va_arg(lst, unsigned long long));
	else if (args == '%')
		len_printed += write(1, "%", 1);
	else
	{   
		len_printed += write(1, "%", 1);
		len_printed += print_char(args);
	}
	return (len_printed);
}		

int	ft_printf(const char *args, ...)
{
	va_list	lst;
	int		len_printed;
	int		stock;
	
	len_printed = 0;
	va_start(lst, args);
	while (*args)
	{
		if (*args == '%')
		{
			stock = 0;
			if (*++args == '\0')
				return (-1);
			stock += prism(lst, *args, len_printed);
			len_printed = stock;  
		}
		else
			len_printed += print_char(*args);
		args++;
	}
	va_end(lst);
	return (len_printed);
}

//int	main ()
//{
//	printf("\n%i\n", ft_printf(" %x ", 4294967296));
//	printf("\n%i\n", printf(" %x ", 4294967296));
//
//	printf("%i\n", ft_printf(" %x %x %x %x %x %x %x", 0, 16, 32, LONG_MIN, ULONG_MAX, 64, -42));
//	printf("%i\n", ft_printf(" %x %x %x %x %x %x ", 1, 1, 1, 1, 1, 1, 1));
//	printf("%i\n", printf(" %x %x %x %x %x %x %x", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
//	return (0);
//}




//gestion des erreurs :
//invalid format specifiers = %f ou %l... = print("Error: invalid format specifier\n")
//insufficient arguments = ("%d%d", 10)... = print("Error: insufficient arguments\n")
//output failure = if return is < 0 so failure to print (stdout closed ?) = print("Error: output failure\n"invalid args = NULL pointer as a string (char *str = NULL, printf("%s", str)) = Print("Error: invalid argument\n") , same using case as previous with the return value

//https://www.gnu.org/software/libc/manual/html_node/Why-Variadic.html
//https://github.com/paulo-santana/ft_printf_tester
//https://github.com/Tripouille/printfTester

//type va_arg (va_list ptr, type) return the value of the next arg and modify ptr to be on the next arg
