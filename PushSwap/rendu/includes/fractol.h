/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadoue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 11:24:12 by aadoue            #+#    #+#             */
/*   Updated: 2023/02/20 14:55:09 by aadoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include <math.h>

# define WIDTH 900
# define HEIGHT 900

typedef struct s_fractol {
	void	*mlx;
	void	*win;
	void	*img;
	void	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		type;
	int		color;
	int		mask;
	int		x;
	int		y;
	int		max_iter;
	double	zoom;
	double	c_r;
	double	c_i;
	double	z_r;
	double	z_i;
	double	x_set;
	double	y_set;
}				t_fractol;

//Key_Management//

int		key_hook(int key, t_fractol *f);
int		mouse_hook(int button, int x, int y, t_fractol *f);

//Fractol Main//

int		destroy(t_fractol *f);

//Drawing//

void	pxl_input(t_fractol *f, int color);
void	print_frac(t_fractol *f);
void	zoom_frac(int x, int y, t_fractol *f);
void	unzoom_frac(int x, int y, t_fractol *f);

//Mandelbrot Set//

void	init_mandel(t_fractol *f);
void	print_mandel(t_fractol *f);

//Julia Set//

void	init_julia(t_fractol *f);
void	preset_julia(t_fractol *f, double rl, double imgn);
void	print_julia(t_fractol *f);

//Burning Ship Set//

void	init_ship(t_fractol *f);
void	print_ship(t_fractol *f);

#endif 
