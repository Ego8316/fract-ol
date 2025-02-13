/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:55:28 by ego               #+#    #+#             */
/*   Updated: 2025/02/12 19:20:18 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_default_range(t_fractal *f)
{
	if (f->set == JULIA)
	{
		f->min.x = -2.0;
		f->min.y = -2.0;
		f->max.x = 2.0;
		f->max.y = 2.0;
	}
	if (f->set == MANDELBROT)
	{
		f->min.x = -2.0;
		f->min.y = -1.5;
		f->max.x = 1.0;
		f->max.y = 1.5;
	}
}

/**
 * @brief Sets the fractal structure to
 * default values.
 * 
 * @param f Pointer to the fractal structure.
 */
void	init_fractal(t_fractal *f)
{
	f->min.x = -2.0;
	f->min.y = -1.5;
	f->max.x = 1.0;
	f->max.y = 1.5;
	f->max_iter = 80;
	f->zoom = 1.0;
	f->c.x = -0.745429;
	f->c.y = 0.05;
}

/**
 * @brief Initializes the fractal structure.
 * First connects to mlx, then creates a new
 * window and and a new image.
 * 
 * @param f Pointer to an empty fractal structure.
 */
void	init_mlx(t_fractal *f)
{
	f->mlx = mlx_init();
	if (!f->mlx)
		clean_exit(f, "MLX: connection to mlx failed.\n", 1);
	f->window = mlx_new_window(f->mlx, WIDTH, HEIGHT, TITLE);
	if (!f->window)
		clean_exit(f, "MLX: window creation failed.\n", 1);
	f->image = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	if (!f->image)
		clean_exit(f, "MLX: image creation failed.\n", 1);
	f->addr = mlx_get_data_addr(f->image, &f->bpp,
			&f->size_line, &f->endian);
}
