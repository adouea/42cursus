/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadoue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 13:21:38 by aadoue            #+#    #+#             */
/*   Updated: 2023/01/03 16:33:22 by aadoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
			return (ft_print_hexa_u(ptr, args));
		return (ft_print_str("(nil)"));
	}
	else if (args == 'd' || args == 'i')
		return (ft_print_int(va_arg(lst, int)));
	else if (args == 'u')
		return (ft_print_uint_hexa(va_arg(lst, unsigned int), "0123456789"));
	else if (args == 'x' || args == 'X')
		return (ft_print_hexa_u(va_arg(lst, unsigned int), args));
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
