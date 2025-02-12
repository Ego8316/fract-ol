/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:45:39 by ego               #+#    #+#             */
/*   Updated: 2025/02/12 15:08:08 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H

# include <../minilibx/mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include "keys.h"

# define WIDTH 900
# define HEIGHT 900
# define TITLE "fract-ol"
# define MAX_ITER 100

typedef struct s_complex
{
	double	x;
	double	y;
}	t_complex;

typedef struct s_fractal
{
	void		*mlx;
	void		*window;
	void		*image;
	void		*addr;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	t_complex	min;
	t_complex	max;
	int			(*func)(t_complex);
}	t_fractal;

void		init_fractal(t_fractal *fractal);
void		clean_exit(t_fractal *f, char *msg, int exit_code);

// Complex operations

double		modulus_squared(t_complex z);
t_complex	addition(t_complex z1, t_complex z2);
t_complex	substraction(t_complex z1, t_complex z2);
t_complex	multiplication(t_complex z1, t_complex z2);

// Fractal sets

int			mandelbrot(t_complex c);
void		render_fractal(t_fractal *f);

void		ft_putstr_fd(const char *s, int fd);

#endif