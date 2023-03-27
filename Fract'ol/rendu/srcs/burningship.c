/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadoue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 13:13:28 by aadoue            #+#    #+#             */
/*   Updated: 2023/03/08 13:13:37 by aadoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	init_ship(t_fractol *f)
{
	f->type = 2;
	f->max_iter = 100;
	f->zoom = 300;
	f->x_set = -1.8;
	f->y_set = -1.8;
}

static void	get_ship_pxl(t_fractol *f)
{
	double	z_next;
	double	z_tmp;
	int		i;

	f->c_r = f->x / f->zoom + f->x_set;
	f->c_i = -(f->y / f->zoom + f->y_set);
	f->z_r = 0.0;
	f->z_i = 0.0;
	i = 0;
	z_next = 0.0;
	while (z_next < 4 && i < f->max_iter)
	{
		z_tmp = fabs(f->z_r);
		f->z_r = f->z_r * f->z_r - f->z_i * f->z_i + f->c_r;
		f->z_i = fabs(2 * f->z_i * z_tmp - f->c_i);
		z_next = f->z_r * f->z_r + f->z_i * f->z_i;
		i++;
	}
	if (i == f->max_iter)
		pxl_input(f, 0);
	else
		pxl_input(f, f->color & ~f->mask * i);
}

void	print_ship(t_fractol *f)
{
	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	f->addr = mlx_get_data_addr(f->img, &f->bpp, &f->line_len, &f->endian);
	f->x = 0;
	while (f->x < WIDTH)
	{
		f->y = 0;
		while (f->y < HEIGHT)
		{
			get_ship_pxl(f);
			f->y++;
		}
		f->x++;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
	mlx_destroy_image(f->mlx, f->img);
}
