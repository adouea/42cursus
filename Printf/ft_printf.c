/*//// ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadoue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 13:21:38 by aadoue            #+#    #+#             */
/*   Updated: 2023/01/03 14:27:25 by aadoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <limits.h>
//#include <stdio.h>
#include "ft_printf.h"

/*static int	print_hexa_min(unsigned long long n, char p)
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
}*/

/*static int	print_hexa_min(unsigned long long n)
{
	static const char	hex_digits[] = "0123456789abcdef";
	char				buf[9];
	char				*pbuf = buf;
	int					count;

	count = 0;
	while (n >= 0)
	{
		*pbuf++ = hex_digits[n % 16];	
		n /= 16;
	}
	while (pbuf > buf)
		count += print_char(*--pbuf);
	return (count);
}*/

static int	prism(va_list lst, const char args)
{
	unsigned long	ptr;

	if (args == 'c')
		return (ft_print_char(va_arg(lst, int)));
	else if (args == 's')
		return (ft_print_str(va_arg(lst, char *)));
	else if (args == 'p')
	{
		ptr = va_arg(lst, unsigned long);
		if (ptr)
			return (ft_print_hexa_u(va_arg(lst, unsigned long long), args));
		return (ft_print_str("(nil)"));
	}
	else if (args == 'd' || args == 'i')
		return (ft_print_int(va_arg(lst, int)));
	else if (args == 'u')
		return (ft_print_uint(va_arg(lst, unsigned int)));
	else if (args == 'x' || args == 'X')
		return (ft_print_hexa_u(va_arg(lst, unsigned long long), args));
	else if (args == '%')
		return (ft_print_char('%'));
	else
		return (-1);
}		

int	ft_printf(const char *args, ...)
{
	va_list	lst;
	int		len_printed;
	int		i;
	
	len_printed = 0;
	i = 0;
	va_start(lst, args);
	while (args[i])
	{
		if (args[i] == '%' && ft_strchr("cspdiuxX%", args[i + 1]) != 0)
		{
			len_printed += prism(lst, args[i + 1]);
			i++;
		}
		else
			len_printed += ft_print_char(args[i]);
		i++;
	}
	va_end(lst);
	return (len_printed);
}

/*int	main ()
{

	printf("\n%i\n", ft_printf("%x", 1254));
	printf("\n%i\n", printf("%x", 1254));

//	printf("\n%i\n", ft_printf("%1c", 'a'));
//	printf("\n%i\n", printf("%1c", 'a'));
//	printf("%i\n", ft_printf(" %x %x %x %x %x %x %x", 0, 16, 32, LONG_MIN, ULONG_MAX, 64, -42));
//	printf("%i\n", ft_printf(" %x %x %x %x %x %x ", 1, 1, 1, 1, 1, 1, 1));
//	printf("%i\n", printf(" %x %x %x %x %x %x %x", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
	return (0);
}*/




//gestion des erreurs :
//invalid format specifiers = %f ou %l... = print("Error: invalid format specifier\n")
//insufficient arguments = ("%d%d", 10)... = print("Error: insufficient arguments\n")
//output failure = if return is < 0 so failure to print (stdout closed ?) = print("Error: output failure\n"invalid args = NULL pointer as a string (char *str = NULL, printf("%s", str)) = Print("Error: invalid argument\n") , same using case as previous with the return value

//https://www.gnu.org/software/libc/manual/html_node/Why-Variadic.html
//https://github.com/paulo-santana/ft_printf_tester
//https://github.com/Tripouille/printfTester

//type va_arg (va_list ptr, type) return the value of the next arg and modify ptr to be on the next arg
