/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:54:32 by ego               #+#    #+#             */
/*   Updated: 2025/02/12 16:28:14 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/**
 * @brief Checks if a complex number belongs to the Mandelbrot set.
 * 
 * @param c Complex number.
 * 
 * @return Number of iterations before divergence (or max if it converges).
 */
int	mandelbrot(t_complex c, int max_iterations)
{
	t_complex	z;
	int			iter;

	z.x = 0;
	z.y = 0;
	iter = 0;
	while (modulus_squared(z) <= 4.0 && iter < max_iterations)
	{
		z = addition(multiplication(z, z), c);
		iter++;
	}
	return (iter);
}
