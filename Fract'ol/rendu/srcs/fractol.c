/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadoue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:57:42 by aadoue            #+#    #+#             */
/*   Updated: 2023/03/17 16:47:09 by aadoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include "../ft_printf/ft_printf.h"

int	destroy(t_fractol *f)
{
	mlx_clear_window(f->mlx, f->win);
	mlx_destroy_window(f->mlx, f->win);
	mlx_destroy_display(f->mlx);
	mlx_loop_end(f->mlx);
	free(f->mlx);
	free(f);
	exit(1);
	return (0);
}

static void	init_mlx(t_fractol	*f)
{
	f->mlx = mlx_init();
	f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, "Fractol");
	f->mask = 0x00F0F0F0;
	f->color = 0x000000FF;
}

static void	init_frac(t_fractol *f, char **av)
{
	if (ft_strcmp(av[1], "mandelbrot") == 0 && !av[2])
		init_mandel(f);
	else if (ft_strcmp(av[1], "julia") == 0)
	{
		if (av[2] && av[3])
			preset_julia(f, ft_atod(av[2]), ft_atod(av[3]));
		else
			init_julia(f);
	}
	else if (ft_strcmp(av[1], "burningship") == 0 && !av[2])
		init_ship(f);
	else
	{
		ft_printf("Use:\n\t./fractol mandelbrot\n\t./fractol julia"
			" (+ option)\n\t./fractol burningship\n");
		destroy(f);
	}
	print_frac(f);
}

int	main(int ac, char **av)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)ft_calloc(1, sizeof(t_fractol));
	if (!fractol)
		return (-1);
	if (ac == 2 || ac == 4)
	{
		init_mlx(fractol);
		init_frac(fractol, av);
		mlx_mouse_hook(fractol->win, mouse_hook, fractol);
		mlx_hook(fractol->win, 17, 1L << 2, &destroy, fractol);
		mlx_key_hook(fractol->win, key_hook, fractol);
		mlx_loop(fractol->mlx);
	}
	else if (ac == 3 && ft_strcmp(av[1], "julia") == 0)
		ft_printf("Use: ./fractol julia <float> <float>\n");
	else
		ft_printf("Use:\n\t./fractol mandelbrot\n\t./fractol julia"
			" (+ arguments)\n\t./fractol burningship\n");
	free(fractol);
	return (0);
}
