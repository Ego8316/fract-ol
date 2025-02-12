/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 17:59:25 by ego               #+#    #+#             */
/*   Updated: 2025/02/12 16:47:00 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	exit_fractal(t_fractal *f)
{
	clean_exit(f, 0, 0);
	return (0);
}

int	main(void)
{
	t_fractal	fractal;

	init_mlx(&fractal);
	init_fractal(&fractal);
	fractal.func = mandelbrot;
	mlx_key_hook(fractal.window, key_hook, &fractal);
	// mlx_mouse_hook(fractal.window, mouse_hook, &fractal);
	mlx_hook(fractal.window, CLOSE_BUTTON, 0, exit_fractal, &fractal);
	render_fractal(&fractal);
	mlx_loop(fractal.mlx);
	return (0);
}
