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

# include "complex.h"
# include "utils.h"

void	draw_fractal(t_data *data);
void	set_up_window(char *name, int code, double def_re, double def_im);

#endif
