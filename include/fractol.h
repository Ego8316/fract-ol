/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:45:39 by ego               #+#    #+#             */
/*   Updated: 2025/02/11 20:32:19 by ego              ###   ########.fr       */
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

# define WIDTH 1280
# define HEIGHT 720
# define TITLE "fract-ol"

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
	t_complex	z;
	t_complex	offset;
}	t_fractal;

void	init_fractal(t_fractal *fractal);
void	clean_exit(t_fractal *f, char *msg, int exit_code);

void	ft_putstr_fd(const char *s, int fd);

#endif