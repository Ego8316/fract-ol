/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:54:32 by ego               #+#    #+#             */
/*   Updated: 2025/02/12 19:13:59 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/**
 * @brief Checks if a complex number belongs to the Julia set.
 * The c number is stocked in the fractal structure.
 * 
 * @param z Complex number.
 * @param f Pointer to the fractal structure.
 */
int	julia(t_complex z, t_fractal *f)
{
	int			iter;

	iter = 0;
	while (modulus_squared(z) <= 4.0 && iter < f->max_iter)
	{
		z = addition(multiplication(z, z), f->c);
		iter++;
	}
	return (iter);
}
/**
 * @brief Checks if a complex number belongs to the Mandelbrot set.
 * 
 * @param c Complex number.
 * @param f Pointer to the fractal structure.
 * 
 * @return Number of iterations before divergence (or max if it converges).
 */
int	mandelbrot(t_complex c, t_fractal *f)
{
	t_complex	z;
	int			iter;

	z.x = 0;
	z.y = 0;
	iter = 0;
	while (modulus_squared(z) <= 4.0 && iter < f->max_iter)
	{
		z = addition(multiplication(z, z), c);
		iter++;
	}
	return (iter);
}
