/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:45:39 by ego               #+#    #+#             */
/*   Updated: 2025/02/25 02:56:19 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <../minilibx/mlx.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <math.h>
# include "keys.h"

# include <stdio.h>

# define WIDTH 900
# define HEIGHT 900
# define TITLE "fract-ol"
# define JULIA 0
# define MANDELBROT 1
# define BURNING_SHIP 2
# define NEWTON 3
# ifndef M_PI
#  define M_PI 3.1415926
# endif

typedef struct s_complex
{
	double	x;
	double	y;
}	t_complex;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_palette
{
	t_color				*colors;
	struct s_palette	*next;
	struct s_palette	*prev;
}	t_palette;

typedef struct s_map
{
	int				(*func)(int, int, t_color *);
	struct s_map	*next;
	struct s_map	*prev;
}	t_map;

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
	t_palette	*palette;
	t_map		*map;
}	t_fractal;

// Initialization

int			init_set(int ac, char **av, t_fractal *f, char set);
int			init_palette(t_fractal *f);
int			init_map(t_fractal *f);
void		init_fractal(t_fractal *f);
void		init_mlx(t_fractal *fractal);

// Event handlers

int			key_hook(int keycode, t_fractal *f);
int			mouse_hook(int mouse_code, int x, int y, t_fractal *f);

// Color maps
int			linear_mapping(int iter, int max_iter, t_color *colors);
int			sinusoidal_mapping(int iter, int max_iter, t_color *colors);
int			noise_mapping(int iter, int max_iter, t_color *colors);

// Rendering function

void		render_fractal(t_fractal *f);

// Fractal sets

int			julia(t_complex z, t_fractal *f);
int			mandelbrot(t_complex c, t_fractal *f);
int			burning_ship(t_complex c, t_fractal *f);
int			newton(t_complex z, t_fractal *f);

// Complex operations

double		modulus_squared(t_complex z);
t_complex	addition(t_complex z1, t_complex z2);
t_complex	multiplication(t_complex z1, t_complex z2);
t_complex	division(t_complex z1, t_complex z2);
double		distance(t_complex z1, t_complex z2);

// Utils

int			ft_strcmp(char *s1, char *s2);
int			ft_strscmp(char *s1, char *s2, char *s);
double		ft_atof(char *nptr);
double		ft_abs(double x);
void		clean_exit(t_fractal *f, char *msg, int exit_code);
int			free_pals(t_palette *f, t_palette *o, t_palette *c, t_palette *p);
int			free_maps(t_map *l, t_map *s, t_map *n);
void		free_color_palette(t_fractal *f);
void		free_color_map(t_fractal *f);

// Display functions

void		ft_putstr_fd(const char *s, int fd);
int			put_help_message(void);
void		put_controls_message(void);

#endif