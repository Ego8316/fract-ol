/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 17:59:25 by ego               #+#    #+#             */
/*   Updated: 2025/02/12 15:07:01 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	pixel_put(t_fractal *f, int x, int y, int color)
{
	char	*dst;

	dst = f->addr + y * f->size_line + x * f->bits_per_pixel / 8;
	*(unsigned int *)dst = color;
}

int	main(void)
{
	t_fractal	fractal;

	init_fractal(&fractal);
	render_fractal(&fractal);
	return (0);
}
