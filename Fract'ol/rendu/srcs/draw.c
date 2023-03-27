/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadoue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:09:27 by aadoue            #+#    #+#             */
/*   Updated: 2023/02/27 15:51:39 by aadoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include "../ft_printf/ft_printf.h"

void	pxl_input(t_fractol *f, int color)
{
	char	*dst;

	dst = f->addr + (f->y * f->line_len + f->x * (f->bpp / 8));
	*(unsigned int *)dst = color;
}

void	print_frac(t_fractol *f)
{
	if (f->type == 0)
		print_mandel(f);
	else if (f->type == 1)
		print_julia(f);
	else if (f->type == 2)
		print_ship(f);
	else
	{
		ft_printf("Can't print fractal\n");
		destroy(f);
	}
}

void	zoom_frac(int x, int y, t_fractol *f)
{
	f->x_set = (x / f->zoom + f->x_set) - (x / (f->zoom * 1.5));
	f->y_set = (y / f->zoom + f->y_set) - (y / (f->zoom * 1.5));
	f->zoom *= 1.5;
}

void	unzoom_frac(int x, int y, t_fractol *f)
{
	f->x_set = (x / f->zoom + f->x_set) - (x / (f->zoom / 1.5));
	f->y_set = (y / f->zoom + f->y_set) - (y / (f->zoom / 1.5));
	f->zoom /= 1.5;
}
