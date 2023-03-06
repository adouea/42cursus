/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadoue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 14:30:38 by aadoue            #+#    #+#             */
/*   Updated: 2023/02/22 16:04:46 by aadoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include "../mlx/mlx.h"

# define SCROLL_UP 4
# define SCROLL_DOWN 5
# define ESC 65307
# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363

# define JUL_CODE 1
# define MAND_CODE 2
# define JUL_NAME "Julia"
# define MAND_NAME "Mandelbrot"
# define ITERS 100

# define JULIA_DEFAULT_RE -1
# define JULIA_DEFAULT_IM 0
# define MANDELBROT_DEFAULT_RE 0
# define MANDELBROT_DEFAULT_IM 0

# define WIDTH 1000
# define HEIGHT 1000
# define MOVE_DELTA 10
# define SCALE_DELTA 1.25

typedef struct s_vars
{
	int	bits_per_pixel;
	int	size_line;
	int	endian;
}	t_vars;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*img_addr;
	int		fract_code;
	int		vert;
	int		horiz;
	double	scale;
	double	x;
	double	y;	
}	t_data;

void	clean_and_exit(int exit_code, t_data *data);
int		cmp_strings(char *s1, char *s2);
int		is_number(char *s);
double	atod(char *s);

#endif
