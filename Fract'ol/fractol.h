/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadoue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 11:24:12 by aadoue            #+#    #+#             */
/*   Updated: 2023/02/15 15:15:15 by aadoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH 800
# define HEIGHT 800
# define MAX_ITERATIONS 50

typedef struct s_complex
{
	double	r;
	double	i;
}	t_complex;


#include "mlx.h"
#include "./libft/libft.h"
#include <math.h>

int	main();

#endif
