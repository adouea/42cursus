/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadoue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 14:59:56 by aadoue            #+#    #+#             */
/*   Updated: 2023/01/03 13:31:04 by aadoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_numlen(long long n, int base);
int ft_unumlen(unsigned long long n, int base);
int	ft_print_char(char c);
int	ft_print_str(char *s);
int	ft_print_int(long long n);
int ft_print_head(unsigned long long n);
int	ft_print_hexa_maj(unsigned long long n);
int	ft_print_hexa_min(unsigned long long n);
int	ft_print_uint(unsigned long long n);
int ft_print_uint_hexa(unsigned long long n, const char *base);
int ft_printf(const char *conv, ...);

#endif

