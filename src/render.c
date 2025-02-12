/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:14:27 by ego               #+#    #+#             */
/*   Updated: 2025/02/12 17:25:33 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_color(int iter, int max_iter)
{
	if (iter == max_iter)
		return (0x000000);
	return ((iter * 255 / max_iter) << 16);
}

/**
 * @brief Puts color to given pixel coordinates.
 * 
 * @param f Pointer to the fractal structure.
 * @param x Pixel x coordinate.
 * @param y Pixel y coordinate.
 * @param color Color code.
 */
void	put_color_to_pixel(t_fractal *f, int x, int y, int color)
{
	*(unsigned int *)(f->addr + (y * f->size_line + x * (f->bpp / 8))) = color;
	return ;
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
			c.x = f->min.x + (double)x * (f->max.x - f->min.x) / WIDTH;
			c.y = f->min.y + (double)y * (f->max.y - f->min.y) / HEIGHT;
			iter = f->func(c, f->max_iter);
			color = get_color(iter, f->max_iter);
			put_color_to_pixel(f, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(f->mlx, f->window, f->image, 0, 0);
}
