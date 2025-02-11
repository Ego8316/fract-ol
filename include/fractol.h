/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:45:39 by ego               #+#    #+#             */
/*   Updated: 2025/02/11 18:23:54 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H

# include <../minilibx/mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include "keys.h"

# define WIDTH 1280
# define HEIGHT 720
# define TITLE "fract-ol"

typedef struct s_data
{
	void	*mlx;
	void	*window;
	void	*image;
}	t_fractal;

typedef struct s_complex
{
	int	x;
	int	y;
}	t_complex;

void	init_fractal(t_fractal *fractal);

#endif