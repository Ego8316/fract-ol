/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:14:27 by ego               #+#    #+#             */
/*   Updated: 2025/02/12 15:14:41 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_color(int iter, int max_iter)
{
	if (iter == max_iter)
		return 0x000000;
	return (iter * 255 / max_iter) << 16;
}

/**
 * @brief Renders the fractal.
 * 
 * @param f Pointer to the fractal structure.
 */
void	render_fractal(t_fractal *f)
{
	int			x;
	int			y;
	int			iter;
	int			color;
	t_complex	c;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			c.x = f->min.x + (double)x / WIDTH * (f->max.x - f->min.x);
			c.y = f->min.y + (double)y / HEIGHT * (f->max.y - f->min.y);
			iter = f->func(c);
			color = get_color(iter, MAX_ITER);
			*(unsigned int *)(f->addr + (y * f->size_line + x * (f->bits_per_pixel / 8))) = color;
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(f->mlx, f->window, f->image, 0, 0);
	mlx_loop(f->mlx);
}
