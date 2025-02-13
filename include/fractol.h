/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:45:39 by ego               #+#    #+#             */
/*   Updated: 2025/02/12 19:43:10 by ego              ###   ########.fr       */
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
# define JULIA 0
# define MANDELBROT 1
# define BURNING_SHIP 2
# define NEWTON 3
# define J "julia"
# define M "mandelbrot"
# define B "burning_ship"
# define N "newton"

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
	int			bpp;
	int			size_line;
	int			endian;
	t_complex	min;
	t_complex	max;
	t_complex	c;
	int			max_iter;
	double		zoom;
	int			set;
	int			(*func)(t_complex, struct s_fractal *);
}	t_fractal;

// Initialization

void		init_mlx(t_fractal *fractal);
void		init_fractal(t_fractal *f);

// Event handlers

int			key_hook(int keycode, t_fractal *f);
int			mouse_hook(int mouse_code, int x, int y, t_fractal *f);

// Rendering function

void		render_fractal(t_fractal *f);

// Fractal sets

int			mandelbrot(t_complex c, t_fractal *f);
int			julia(t_complex z, t_fractal *f);

// Complex operations

double		modulus_squared(t_complex z);
t_complex	addition(t_complex z1, t_complex z2);
t_complex	substraction(t_complex z1, t_complex z2);
t_complex	multiplication(t_complex z1, t_complex z2);

// Utils

int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		clean_exit(t_fractal *f, char *msg, int exit_code);

// Display functions

void		ft_putstr_fd(const char *s, int fd);

#endif