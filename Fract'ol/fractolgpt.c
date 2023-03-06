/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractolgpt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadoue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:25:11 by aadoue            #+#    #+#             */
/*   Updated: 2023/02/15 14:42:14 by aadoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include <stdio.h>

typedef struct s_fractal {
    double x_min;
    double x_max;
    double y_min;
    double y_max;
    int max_iter;
    void *mlx_ptr;
    void *win_ptr;
} t_fractal;

int mandelbrot_iter(double cx, double cy, int max_iter)
{
    double zx = 0.0;
    double zy = 0.0;
    double zx_new;
    int i;

    for (i = 0; i < max_iter; i++) {
        zx_new = zx * zx - zy * zy + cx;
        zy = 2 * zx * zy + cy;
        zx = zx_new;
        if (zx * zx + zy * zy > 4)
            break;
    }
    return i;
}

void draw_fractal(t_fractal *fractal)
{
    int x, y, i;

    for (y = 0; y < 500; y++) {
        for (x = 0; x < 500; x++) {
            double cx = fractal->x_min + (double)x / 500 * (fractal->x_max - fractal->x_min);
            double cy = fractal->y_min + (double)y / 500 * (fractal->y_max - fractal->y_min);
            i = mandelbrot_iter(cx, cy, fractal->max_iter);
            if (i == fractal->max_iter)
                mlx_pixel_put(fractal->mlx_ptr, fractal->win_ptr, x, y, 0);
            else
                mlx_pixel_put(fractal->mlx_ptr, fractal->win_ptr, x, y, 0xFFFFFF / fractal->max_iter * i);
        }
    }
}

int main(void)
{
    t_fractal fractal = {
        .x_min = -2.0,
        .x_max = 1.0,
        .y_min = -1.5,
        .y_max = 1.5,
        .max_iter = 50
    };

    fractal.mlx_ptr = mlx_init();
    fractal.win_ptr = mlx_new_window(fractal.mlx_ptr, 50, 50, "Mandelbrot Set");

    draw_fractal(&fractal);

    mlx_loop(fractal.mlx_ptr);

    return 0;
}

