/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadoue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 13:00:14 by aadoue            #+#    #+#             */
/*   Updated: 2023/03/17 16:45:15 by aadoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include "../ft_printf/ft_printf.h"

void	init_julia(t_fractol *f)
{
	f->type = 1;
	f->max_iter = 100;
	f->zoom = 300;
	f->x_set = -1.5;
	f->y_set = -1.4;
	f->c_r = -0.5;
	f->c_i = 0.5;
}

void	preset_julia(t_fractol *f, double rl, double imgn)
{
	init_julia(f);
	f->c_r = rl;
	f->c_i = imgn;
}

static void	get_julia_pxl(t_fractol *f)
{
	double	z_next;
	double	z_rtmp;
	int		i;

	f->z_r = (f->x / f->zoom + f->x_set);
	f->z_i = (f->y / f->zoom + f->y_set);
	z_next = f->z_r * f->z_r + f->z_i * f->z_i;
	i = 0;
	while (z_next < 4 && i < f->max_iter)
	{
		z_rtmp = f->z_r * f->z_r - f->z_i * f->z_i;
		f->z_i = 2 * f->z_r * f-> z_i + f->c_i;
		f->z_r = z_rtmp + f->c_r;
		z_next = f->z_r * f->z_r + f->z_i * f->z_i;
		i++;
	}
	if (i == f->max_iter)
		pxl_input(f, 0);
	else
		pxl_input(f, f->color & ~f->mask * i);
}

void	print_julia(t_fractol *f)
{
	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	f->addr = mlx_get_data_addr(f->img, &f->bpp, &f->line_len, &f->endian);
	f->x = 0;
	while (f->x < WIDTH)
	{
		f->y = 0;
		while (f->y < HEIGHT)
		{
			get_julia_pxl(f);
			f->y++;
		}
		f->x++;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
	mlx_destroy_image(f->mlx, f->img);
}
