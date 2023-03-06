/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadoue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:20:14 by aadoue            #+#    #+#             */
/*   Updated: 2023/02/22 16:33:16 by aadoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/complex.h"

t_complex	*complex_sum(t_complex *left, t_complex *right)
{
	t_complex	*res;

	res = init_complex(left->re + right->re, left->im + right->im);
	return (res);
}

t_complex	*complex_multi(t_complex *left, t_complex *right)
{
	t_complex	*res;

	res = init_complex(left->re * right->re - left->im * right->im,
		left->re * right->im + left->im * right->re);
	return (res);
}

t_complex	*complex_power_2(t_complex *number)
{
	t_complex	*res;

	res = complex_multi(number, number);
	return (res);
}

t_complex	*init_complex(double re, double im)
{
	t_complex	*number;

	number = (t_complex *)malloc(sizeof(t_complex));
	if (!number)
		return (NULL);
	number->re = re;
	number->im = im;
	number->value = sqrt(pow(re, 2) + pow(im, 2));
	return (number);
}
