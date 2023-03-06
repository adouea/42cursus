/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadoue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 13:28:39 by aadoue            #+#    #+#             */
/*   Updated: 2023/02/27 13:52:48 by aadoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	key_pressed(int	key_code, t_data *data)
{
	if (key_code == ESC)
		clean_and_exit(0, data);
	else if (key_code == UP)
		data->vert -= MOVE_DELTA;
	else if (key_code == DOWN)
		data->vert += MOVE_DELTA;
	else if (key_code == LEFT)
		data->horiz -= MOVE_DELTA;
	else if (key_code == RIGHT)
		data->horiz += MOVE_DELTA;
	draw_fractal(data);
	return (0);
}

int	mouse_pressed(int key_code, int x, int y, t_data *data)
{
	if (key_code == SCROLL_UP)
		data->scale *= SCALE_DELTA;
	else if (key_code == SCROLL_DOWN)
		data->scale /= SCALE_DELTA;
	else
	{
		mlx_mouse_get_pos(data->mlx, data->win, &x, &y);
		data->x = -2.0 + (4.0 / WIDTH) * x;
		data->y = -2.0 + (4.0 / HEIGHT) * y;
		ft_printf("%f %f\n", data->x, data->y);
	}
	draw_fractal(data);
	return (0);
}

t_data	*init_window(char *name)
{
	t_data	*data;
	
	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		exit(1);
	data->mlx = mlx_init();
	if (!data->mlx)
	{
		free(data);
		exit(1);
	}
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, name);
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->win || !data->img)
		clean_and_exit(1, data);
	return (data);
}

void	set_up_window(char *name, int code, double def_re, double def_im)
{
	t_data	*data;

	data = init_window(name);
	data->fract_code = code;
	data->scale = 1.0;
	data->vert = 0;
	data->horiz = 0;
	mlx_mouse_hook(data->win, mouse_pressed, data);
	mlx_hook(data->win, 2, 1L << 0, key_pressed, data);
	data->x = def_re;
	data->y = def_im;
	draw_fractal(data);
	mlx_loop(data->mlx);
}
