/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadoue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:57:42 by aadoue            #+#    #+#             */
/*   Updated: 2023/02/22 16:17:12 by aadoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	main(int argc, char **argv)
{
	if (argc < 2
		|| (cmp_strings(JUL_NAME, argv[1]) && cmp_strings(MAND_NAME, argv[1])))
	{
		ft_printf("Wrong Input: <%s, %s>", JUL_NAME, MAND_NAME);
		return (1);
	}
	if (!cmp_strings(JUL_NAME, argv[1]))
	{
		if (argc == 2 || argc == 3
			|| (argc >= 4 && (!is_number(argv[2]) || !is_number(argv[3]))))
			set_up_window(argv[1],
				JUL_CODE, JULIA_DEFAULT_RE, JULIA_DEFAULT_IM);
		else
			set_up_window(argv[1], JUL_CODE, atod(argv[2]), atod(argv[3])); 
	}
	else
		set_up_window(argv[1], MAND_CODE,
			MANDELBROT_DEFAULT_RE, MANDELBROT_DEFAULT_IM);
	return (0);
}
