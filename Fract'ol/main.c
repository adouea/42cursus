/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadoue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:38:05 by aadoue            #+#    #+#             */
/*   Updated: 2023/02/15 15:15:20 by aadoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mlx()
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "fractoling");
	 

		
	mlx_pixel_put(mlx_ptr, win_ptr, 250, 250, 0xFFFFFF);
	mlx_pixel_put(mlx_ptr, win_ptr, 251, 250, 0xFFFFFF);
	mlx_pixel_put(mlx_ptr, win_ptr, 250, 251, 0xFFFFFF);
	mlx_pixel_put(mlx_ptr, win_ptr, 251, 251, 0xFFFFFF);

	mlx_loop(mlx_ptr);
	return (0);
}




int	main(int argc, char *argv)
{
	if (argc != 2)
		return (error ou null);
	return (0);
}


/*
Fractoling :

-init graphic window with mlx_init();
-create window with mlx_new_window();
-draw image/pixel/line;
-event gestion with mlx_hook() for callback function, mlx_loop() to start main loop of event gestions
(mouse scrolling, 
- compilation : gcc -o fractal fractal.c -lmlx -lm -lX11 -lXext

*/

/*
Questioning :

-mlx_pixel_put ? mlx_rectangle ? mlx_line ?


*/







void    draw_mandelbrot(t_complex min, t_complex max, void *mlx_ptr, void *win_ptr)
{
  int x, y;
  t_complex c;
  t_complex z;
  int iterations;
  int color;

  void    *img_ptr;
  char    *data;
  int     bpp;
  int     size_line;
  int     endian;

  img_ptr = mlx_new_image(mlx_ptr, WIDTH, HEIGHT);
  data = mlx_get_data_addr(img_ptr, &bpp, &size_line, &endian);

  for (x = 0; x < WIDTH; x++)
  {
    for (y = 0; y < HEIGHT; y++)
    {
      c.r = ((double)x / WIDTH) * (max.r - min.r) + min.r;
      c.i = ((double)y / HEIGHT) * (max.i - min.i) + min.i;
      z = (t_complex){ .r = 0, .i = 0 };
      iterations = 0;

      while (z.r * z.r + z.i * z.i < 4 && iterations < MAX_ITERATIONS)
      {
        double tmp = z.r;
        z.r = z.r * z.r - z.i * z.i + c.r;
        z.i = 2 * z.i * tmp + c.i;
        iterations++;
      }

      if (iterations == MAX_ITERATIONS)
        color = 0x000000; // black
      else
        color = 0xFFFFFF * (1 - exp(-0.1 * iterations)); // gradient color

      *(unsigned int*)(data + (x * 4) + (y * size_line))









#include "mlx.h"
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
        .y_max = 

