/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadoue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 14:59:56 by aadoue            #+#    #+#             */
/*   Updated: 2022/12/31 14:57:31 by aadoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int ft_printf(const char *conv, ...);
int	numlen(long long n, int base);
int unumlen(unsigned long long n, int base);
int	print_char(char c);
int	print_str(char *s);
int	print_int(long long n);
int	print_uint(unsigned long long n);

#endif

