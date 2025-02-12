/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:55:28 by ego               #+#    #+#             */
/*   Updated: 2025/02/11 20:29:29 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/**
 * @brief Initializes a fractal structure.
 * First connects to mlx, then creates a new
 * window and and a new image.
 * 
 * @param f Pointer to an empty fractal structure.
 */
void	init_fractal(t_fractal *f)
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
	f->addr = mlx_get_data_addr(f->image, &f->bits_per_pixel,
			&f->size_line, &f->endian);
}
